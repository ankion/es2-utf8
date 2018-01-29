// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
        "你", "你", "我", "他", "她", "它", "它",
        "安尼席洛特爾",
});

private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
private init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);

void create() 
{
        seteuid(getuid());
        set("channel_id", "連線精靈");
}

void logon(object ob)
{
        object *usr;
        int i, wiz_cnt, ppl_cnt, login_cnt;

        cat(WELCOME);
        UPTIME_CMD->main();

        usr = users();
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( !environment(usr[i]) ) login_cnt++;
                else if( wizardp(usr[i]) ) wiz_cnt++;
                else ppl_cnt++;
        }
        printf("目前共有 %d 位巫師、%d 位玩家在線上，以及 %d 位使用者嘗試連線中。\n\n",
                wiz_cnt, ppl_cnt, login_cnt );

        write("您的英文名字：");
        input_to( (: get_id :), ob );
}

private void get_id(string arg, object ob)
{
        object ppl;


        arg = lower_case(arg);
        if( !check_legal_id(arg)) {
                write("您的英文名字：");
                input_to("get_id", ob);
                return;
        }

#ifdef MAX_USERS
        if( (string)SECURITY_D->get_status(arg)=="(player)"
        && sizeof(users()) >= MAX_USERS ) {
                ppl = find_body(arg);
        // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) ) {
                        write("對不起，" + MUD_NAME + 
"的使用者已經太多了，請待會再來。\n");
                        destruct(ob);
                        return;
                }
        }
#endif

//        if( wiz_level(arg) < wiz_lock_level ) {
//                write("對不起，" + MUD_NAME + "目前限制巫師等級 " + 
//WIZ_LOCK_LEVEL
//                        + " 以上的人才能連線。\n");
//                destruct(ob);
//                return;
//        }
        
        if( (string)ob->set("id", arg) != arg ) {
                write("Failed setting user name.\n");
                destruct(ob);
                return;
        }

        if( arg=="guest" ) {
                // If guest, let them create the character.
                confirm_id("Yes", ob);
                return;
        } else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 
) {
                if( ob->restore() ) {
                        write("請輸入密碼：");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write("您的人物儲存擋出了一些問題，請利用 guest 
人物通知巫師處理。\n");
                destruct(ob);
                return;
        }

        write("使用 " + (string)ob->query("id") + " 
這個名字將會創造一個新的人物，您確定嗎(y/n)？");
        input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
        string my_pass;
        object user;

        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass ) {
                write("密碼錯誤！\n");
                destruct(ob);
                return;
        }

        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user) {
                if( user->query_temp("netdead") ) {
                        reconnect(ob, user);
                        return;
                }
                
write("您要將另一個連線中的相同人物趕出去，取而代之嗎？(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( objectp(user = make_body(ob)) ) {
                if( user->restore() ) {
                        log_file( "USAGE", sprintf("%s loggined from %s 
(%s)\n", user->query("name"),
                                query_ip_name(ob), ctime(time()) ) );
                        enter_world(ob, user);
                        return;
                } else {
                        destruct(user);
                }
        }
        write("請您重新創造這個人物。\n");
        confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                
write("您要將另一個連線中的相同人物趕出去，取而代之嗎？(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("好吧，歡迎下次再來。\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "有人從別處( " + query_ip_number(ob)
                        + " )連線取代你所控制的人物。\n");
                log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", 
user->query("name"),
                        query_ip_name(ob), ctime(time()) ) );
        }

        // Kick out tho old player.
        old_link = user->query_temp("link_ob");
        if( old_link ) {
                exec(old_link, user);
                destruct(old_link);
        }

        reconnect(ob, user);    
}

private void confirm_id(string yn, object ob)
{
        if( yn=="" ) {
                write("使用這個名字將會創造一個新的人物，您確定嗎(y/n)？");
                input_to("confirm_id", ob);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("好吧，那麼請重新輸入您的英文名字：");
                input_to("get_id", ob);
                return;
        }

        write( @TEXT

請您想一個有氣質，有個性，又不會太奇怪的中文名字，特別要提醒您
的是，本 mud 是一個以古中國與東方爲背景的世界 ，請不要取一些不
雅或是容易造成他人困擾的名字，這個名字將代表你的人物，而且往後
將不能再更改，請務必慎重。
  ^^^^^^^^^^
(除了名字之外，本 mud 有許多取綽號、別稱的設計，所以鄭重建議您
 取一個比較像名字的中文名字。)

TEXT
        );
        write("您的中文名字：");
        input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
        if( !check_legal_name(arg) ) {
                write("您的中文名字：");
                input_to("get_name", ob);
                return;
        }

        printf("%O\n", ob);
        ob->set("name", arg);
        write("請設定您的密碼：");
        input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
        write("\n");
        if( strlen(pass)<5 ) {
                write("密碼的長度至少要五個字元，請重設您的密碼：");
                input_to("new_password", 1, ob);
                return;
        }
        ob->set("password", crypt(pass,0) );
        write("請再輸入一次您的密碼，以確認您沒記錯：");
        input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
        string old_pass;
        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("您兩次輸入的密碼並不一樣，請重新設定一次密碼：");
                input_to("new_password", 1, ob);
                return;
        }

        write("您的電子郵件地址：");
        input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
        object user;

        ob->set("email", email);

  // If you want do race stuff, ask player to choose one here, then you can
  // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
                return;

        write("您要扮演男性(m)的角色或女性(f)的角色？");
        input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
        if( gender=="" ) {
                write("您要扮演男性(m)的角色或女性(f)的角色？");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "男性");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "女性" );
        else {
                write("對不起，您只能選擇男性(m)或女性(f)的角色：");
                input_to("get_gender", ob, user);
                return;
        }

        log_file( "USAGE", sprintf("%s was created from %s (%s)\n", 
user->query("id"),
                query_ip_name(ob), ctime(time()) ) );
        init_new_player(user);
        enter_world(ob, user);
}

object make_body(object ob)
{
        string err;
        object user;
        int n;

        user = new(ob->query("body"));
        if(!user) {
                
write("現在可能有人正在修改使用者物件的程式，無法進行復制。\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}

private init_new_player(object user)
{
        user->set("title", "普通百姓");
        user->set("birthday", time() );
        user->set("potential", 99);

        user->set("str", 30/*10 + random(21)*/);
        user->set("cps", 30/*10 + random(21)*/);
        user->set("int", 30/*10 + random(21)*/);
        user->set("cor", 30/*10 + random(21)*/);
        user->set("con", 30/*10 + random(21)*/);
        user->set("spi", 30/*10 + random(21)*/);
        user->set("per", 30/*10 + random(21)*/);
        user->set("kar", 30/*10 + random(21)*/);
	user->set("gift_tag", 1);

        user->set("food", user->max_food_capacity());
        user->set("water", user->max_water_capacity());

        user->set("channels", ({ "chat" }) );
}

varargs void enter_world(object ob, object user, int silent)
{
        object cloth, room;
        string startroom;

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        write("目前權限：" + wizhood(user) + "\n");
        user->setup();

        // In case of new player, we save them here right aftre setup 
        // compeleted.
        user->save();
        ob->save();

	// check if need allot gift
	if ( user->query("gift_tag") )
		if ( user->query("age") >= 15) {
        		user->set("str", 10 + random(21));
        		user->set("cps", 10 + random(21));
        		user->set("int", 10 + random(21));
        		user->set("cor", 10 + random(21));
        		user->set("con", 10 + random(21));
        		user->set("spi", 10 + random(21));
        		user->set("per", 10 + random(21));
        		user->set("kar", 10 + random(21));
        		user->delete("gift_tag");
			}

        cloth = new("/obj/cloth");
        cloth->move(user);
        cloth->wear();

        if( !silent ) {
                cat(MOTD);
                if( ob->query("new_mail") ) {
                        write( GRN + 
"\n杜寬告訴你：有您的信！請到驛站來一趟...\n\n" + NOR);
                        ob->set("new_mail", 0);
                }
                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( !stringp(startroom = user->query("startroom")) )
                        startroom = START_ROOM;

                if( !catch(load_object(startroom)) )
                        user->move(startroom);
                else {
                        user->move(START_ROOM);
                        startroom = START_ROOM;
                        user->set("startroom", START_ROOM);
                }
                tell_room(startroom, user->query("name") + 
"連線進入這個世界。\n",
                        ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s由%s連線進入。", user->name(), 
query_ip_name(user)) );
        UPDATE_D->check_user(user);
}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        user->reconnect();
        if( !silent ) {
                tell_room(environment(user), user->query("name") + 
"重新連線回到這個世界。\n",
                ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s由%s重新連線進入。", user->query("name"), 
query_ip_name(user)) );
        UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
        int i;

        i = strlen(id);
        
        if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
                write("對不起，你的英文名字必須是 3 到 12 個英文字母。\n");
                return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write("對不起，你的英文名字只能用英文字母。\n");
                        return 0;
                }

        return 1;
}

int check_legal_name(string name)
{
        int i;

        i = strlen(name);
        
        if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
                write("對不起，你的中文名字必須是 1 到 6 箇中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("對不起，你的中文名字不能用控制字元。\n");
                        return 0;
                }
        }
        if( !is_chinese(name) ) {
                write("對不起，請您用「中文」取名字。\n");
                return 0;
        }
        if( member_array(name, banned_name)!=-1 ) {
                write("對不起，這種名字會造成其他人的困擾。\n");
                return 0;
        }

        return 1;
}

object find_body(string name)
{
        object ob, *body;

        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i])
                &&      getuid(body[i]) == name ) return body[i];

        return 0;
}

int set_wizlock(int level)
{
        if( wiz_level(this_player(1)) <= level )
                return 0;
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        wiz_lock_level = level;
        return 1;
}
 
