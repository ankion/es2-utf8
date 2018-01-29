// look.c

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

string *per_msg = ({
	"可是人間仙子！\n",
	"有沉魚落雁之容，美如天仙！\n",
	"面容姣好，頗有幾分姿色。\n",
	"笑顏如桃花，討人喜愛。\n",
	"相貌普普通通。\n",
	"的相貌嘛，。。。馬馬虎虎吧。\n",
});

string *per_msg_m = ({
	"可貌似潘安，瀟灑異常。\n",
	"人長得挺英俊的，頗吸引人。\n",
	"濃眉大目的，有點男子漢的氣概。\n",
	"五官端正，相貌平常。\n",
	"相貌猥瑣，看起來不怎麼舒服。\n",
});

void create() { seteuid(getuid()); } 

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me));
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	} else result = look_room_item(me, arg);

	return result;
}

int look_room(object me, object env)
{
	int i;
	object *inv;
	mapping exits;
	string str, *dirs;

	if( !env ) {
		write("你的四周灰濛濛地一片，什麼也沒有。\n");
		return 1;
	}
	str = sprintf( "\n▲ %s - %s\n  %s\n%s",
		env->query("short"),
		file_name(env),
		replace_string(env->query("long"), "\n", ""),
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "  這裏沒有任何明顯的出路。\n";
		else if( sizeof(dirs)==1 )
			str += "  這裏唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
		else
			str += sprintf("  這裏明顯的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
				implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
	}
//	str += env->door_description();

	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
		if( !me->visible(inv[i]) ) continue;
		str += "  " + inv[i]->short() + "\n";
	}

	write(str);
	return 1;
}

int look_item(object me, object obj)
{
    string str;
	mixed *inv;

    str = sprintf( "\n◆ %s\n%s\n", obj->short(), replace_string(obj->long(), "\n", "") );
    write(str);

    inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object() );
		message("vision", sprintf("裏面有：\n  %s\n",
			implode(inv, "\n  ") ), me);
	}
	return 1;
}

int look_living(object me, object obj)
{
	string str, pro, inq;
	mixed *inv;
	mapping my_fam, fam;
	int personal;

	if( me!=obj )
		message("vision", me->name() + "正盯著你看，不知道打些什麼主意。\n", obj);

    str = sprintf( "\n▼ %s\n%s\n", obj->short(), replace_string(obj->long(), "\n", "") );

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

	if( (string)obj->query("race")=="人類"
	&&	intp(obj->query("age")) )
		str += sprintf("%s看起來約%s多歲。\n", pro, chinese_number(obj->query("age") / 10 * 10));

	
	// 查看相貌
	if (me == obj) {
		if ((int)me->query("age") > 14)
			str += sprintf("你很象鏡子中的自己啊!\n");
		    else 
			str += sprintf("你才十四歲啊，有什麼好看的？\n");
		}
	    else if((string)obj->query("race")=="人類"){
		if ((int)obj->query("age") < 15)
			str += sprintf("十四歲的小孩都是天天真真的模樣。\n");
		    else {
			personal = (int)obj->query("per");		
			if (obj->query("gender") == "女性") {
				if (personal >= 30)
					str += sprintf(pro + per_msg[0]);
				  else if (personal >= 26)
					str += sprintf(pro + per_msg[1]);
			  	   else if (personal >= 22)
					str += sprintf (pro + per_msg[2]);
				    else if (personal >= 17)
					str += sprintf(pro + per_msg[3]);
				     else if (personal >= 13)
					str += sprintf(pro + per_msg[4]);
				      else
					str += sprintf(pro + per_msg[5]);
				}
			    else {
				if (personal >= 26)
					str += sprintf(pro + per_msg_m[0]);
				  else if (personal >= 22)
					str += sprintf(pro + per_msg_m[1]);
				  else if (personal >= 17)
					str += sprintf(pro+ per_msg_m[2]);
				   else if (personal >= 13)
					str += sprintf(pro + per_msg_m[3]);
				    else 
					str += sprintf(pro + per_msg_m[4]);
				}
			}
		}
	// If we both has family, check if we have any relations.
	if( obj!=me
	&&	mapp(fam = obj->query("family"))
	&&	mapp(my_fam = me->query("family")) 
	&&	fam["family_name"] == my_fam["family_name"] ) {
	
		if( fam["generation"]==my_fam["generation"] ) {
			if( (string)obj->query("gender") == "男性" )
				str += sprintf( pro + "是你的%s%s。\n",
					my_fam["master_id"] == fam["master_id"] ? "": "同門",
					my_fam["enter_time"] > fam["enter_time"] ? "師兄": "師弟");
			else
				str += sprintf( pro + "是你的%s%s。\n",
					my_fam["master_id"] == fam["master_id"] ? "": "同門",
					my_fam["enter_time"] > fam["enter_time"] ? "師姐": "師妹");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( my_fam["master_id"] == obj->query("id") )
				str += pro + "是你的師父。\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "是你的同門長輩。\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "是你的師伯。\n";
			else
				str += pro + "是你的師叔。\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "是你的同門晚輩。\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "是你的弟子。\n";
			else
				str += pro + "是你的師侄。\n";
		}
	}

	if( obj->query("max_kee") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";

	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
			str += sprintf( obj->is_corpse() ? "%s的遺物有：\n%s\n" : "%s身上帶著：\n%s\n",
				pro, implode(inv, "\n") );
	}

    if( mapp(obj->query("vendor_goods")) ) {
      str = str + obj->get_vendor_list();
    }

	message("vision", str, me);

	if( obj!=me 
	&&	living(obj)
	&&	random((int)obj->query("bellicosity")/10) > (int)me->query("per") ) {
		write( obj->name() + "突然轉過頭來瞪你一眼。\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
	}

	return 1;
}

string inventory_look(object obj, int flag)
{
	string str;

	str = obj->short();
	if( obj->query("equipped") )
		str = HIC "  □" NOR + str;
	else if( !flag )
		str = "    " + str;
	else
		return 0;

	return str;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("這裏只有灰濛濛地一片，什麼也沒有。\n");

	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write("※ "+item[arg]);
		else if( functionp(item[arg]) )
			write("※ "+(string)(*item[arg])(me));
			
		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = find_object(exits[arg])) )
			look_room(me, env);
		else {
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]));
		}
		return 1;
	}
	return notify_fail("你要看什麼？\n");
}

int help (object me)
{
	write(@HELP
指令格式: look [<物品>|<生物>|<方向>]
 
這個指令讓你查看你所在的環境、某件物品、生物、或是方向。
 
HELP
);
	return 1;
}
