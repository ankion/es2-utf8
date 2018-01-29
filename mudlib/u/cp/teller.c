#include <ansi.h>

inherit NPC;

string *first_name = ({ "趙","錢","孫","李","周","吳","鄭","王","張","陳",
        "劉","林" });
string *name_words = ({ "順","昌","振","發","財","俊","彥","良","志","忠",
        "孝","雄","益","添","金","輝","長","盛","勝","進","安","福","同",
        "滿","富","萬","龍","隆","祥","棟","國","億","壽" });

string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *rnd_say = ({
        "我是新手，請告訴我如何玩這個遊戲。",
        "爲什麼我的精氣神都不會恢復？",
        "有誰可以給我一些錢？",
        "這裏的人都不理我！",
        "可不可以告訴我哪裏可以練功\？",
        "hi",
        "hello",
        "hello",
        "hmm",
        "wa...",
        "waley",
        "wait...",
        "hohoho",
        "hehe",
        "ah..",
});

varargs void drool(string msg, string who);

void create()
{
        string name, id;

        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];

        id = rnd_id[random(sizeof(rnd_id))];
        if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];

        set_name(name, ({ id, "drooler" }) );
        set("title", "普通百姓");
        set("gender", "男性");
        set("age", 14);
        set("attitude", "friendly");
        set("attitude", "friendly");
        set("combat_exp", 100);
        set("env/wimpy", 100);
        set("chat_chance", 30);
        set("chat_msg", ({
                (: command, "get all" :),
                (: command, "wear all" :),
                (: command, "wield all" :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
           }) );
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "！", "");
        msg = replace_string(msg, "啊", "");
        msg = replace_string(msg, "嗎", "");
        msg = replace_string(msg, "耶", "");
        msg = replace_string(msg, "吧", "");
        msg = replace_string(msg, "吧", "");

        if( msg!="" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
        string who, phrase;

        if( !userp(ob) || (channel != "chat") ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
        string who, phrase;
        string who, phrase;

        if( !userp(ob) ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                if( random(10)<5 ) {
                        command("chat 爲什麼踢我？會痛耶！");
                        break;
                }
        default:
                if( random(10)<5 )
                        command(verb + " " + ob->query("id"));
                else
                        drool();
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if( (strsrch(msg, "爲什麼") >= 0) ) {
                if( sscanf(msg, "%*s爲什麼%s", msg)==2 ) msg = "爲什麼" + msg;
                switch(random(8)) {
                case 0: command("chat " + who + "，你是在問我嗎？"); 
			break;
                case 1: command("chat 關於" + msg + " ... "); 
			break;
                case 2: command("chat 呃 ... "); drool(); 
			break;
                case 3: command("chat 這個問題嘛 ...."); 
			break;
                case 4: command("chat " + who + "，知道這個問題的答案對你那麼重要嗎？"); 
			break;
                case 5: command("chat " + msg + "？"); 
			break;
                case 6: command("chat " + who + "你能不能說清楚一點？"); 
			break;
                case 7: command("chat " + who + "，我不懂你問的問題"); 
			break;
                	}
        }
        else if( (strsrch(msg, "你") >= 0)
        ||      (strsrch(msg, "□") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
                msg = replace_string(msg, "你", "我");
                msg = replace_string(msg, "□", "我");
                switch(random(10)) {
                case 0: command("chat " + who + "，你是說" + msg + "嗎？");      
			break;
                case 1: command("chat 你確定" + msg + "？");     
			break;
                case 2: command("chat " + msg + "跟你有什麼關係？");     
			break;
                case 3: command("chat 嗯 ... " + who + "說得好"); 
			break;
                case 4: command("chat " + who + "你爲什麼對" + msg + "這麼有興趣？"); 
			break;
                case 5: command("chat 爲什麼你認爲" + msg + "？"); 
			break;
                case 6: command("chat 換個話題吧"); drool(); 
			break;
                case 7: command("chat 纔怪"); 
			break;
                case 8: command("chat 不一定吧？"); 
			break;
                case 9: command("chat 有這個可能 ...."); 
			break;
                }
        }
        else if( (strsrch(msg, "我") >= 0)) {
                if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
                msg = replace_string(msg, "我", "你");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("chat 你是說" + msg + "嗎？"); break;
                case 1: command("chat 真的？" + msg + "？");     break;
                case 2: command("chat 如果" + msg + "，我能幫你什麼忙嗎？");     
			break;
                case 3: command("hmm"); break;
                case 4: command("chat 你認爲" + msg + "？"); break;
                case 5: command("chat 我有同感"); break;
                case 6: command("chat 你說的「" + msg + "」我不能苟同"); 
			break;
                case 7: command("chat 有關「" + msg + "」的話題到此爲止好嗎？"); 
			break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("chat 爲什麼說" + msg + "?"); 
				break;
                        case 1: command("chat 「" + msg + "」是什麼意思？"); 
				break;
                        case 2: command("chat " + msg + "？"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("chat ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("chat " + rnd_say[random(sizeof(rnd_say))]); break
;
                        case 9: command("chat 你怎麼知道" + msg + "?"); break;
                        case 10: command("chat 剛剛" + who + "不是說了，" + msg); 
				break;
                        case 11: command("chat 我當然知道，" + msg); break;
                        case 12: command("chat 然後呢？"); break;
                        case 13: command("chat 真的嗎？"); break;
                        case 14: command("chat 我不這麼認爲。"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}

int accept_object()
{
        return 1;
}

