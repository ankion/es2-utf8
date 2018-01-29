// recruit.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_rec;
	mapping family;
	int i;

	if( !arg ) return notify_fail("指令格式：recruit [cancel]|<對象>\n");

	if( arg=="cancel" ) {
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("你現在並沒有收錄任何人爲弟子的意思。\n");
		write("你改變主意不想收" + old_rec->name() + "爲弟子了。\n");
		tell_object(old_rec, me->name() + "改變主意不想收你爲弟子了。\n");
		me->delete_temp("pending/recruit");
		return 1;
	}

	if( !(ob = present(arg, environment(me))) )
		return notify_fail("你想收誰作弟子？\n");

	if( ob==me ) return notify_fail("收自己爲弟子？好主意....不過沒有用。\n");

	if (userp(me))
		if ( me->query("title") != "普通百姓"
	    	|| me->query("combat_exp") < 20000
            	|| me->query("age") < 18)
		return notify_fail("你似乎不夠收徒的條件哦。。\n");
	
	if( ob->is_apprentice_of(me) ) {
		message_vision("$N拍拍$n的頭，說道：「好徒兒！」\n", me, ob);
		return 1;
	}

/*	if( !me->query("family") )
		return notify_fail("你並不屬於任何門派，你必須先加入一個門派，或自己創一個才能收徒。\n");
*/
	// If the target is willing to apprentice us already, we do it.
	if( (object)ob->query_temp("pending/apprentice") == me ) {

		if( !living(ob) ) {
			message_vision(
				"$N決定收$n爲弟子。\n\n"
				"不過看樣子$n顯然沒有辦法行拜師之禮。\n\n",
				me, ob);
			return 1;
		}
	// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
		if((ob->query("family")) && ( (string)me->query("family/family_name") != (string)ob->query("family/family_name") ) ) {
			message_vision(
				"$N決定背叛師門，改投入$n門下！！\n\n"
				"$N跪了下來向$n恭恭敬敬地磕了四個響頭，叫道：「師父！」\n\n",
				ob, me);
			ob->set("score", 0);
			ob->add("betrayer", 1);
		} else
			message_vision(
				"$N決定收$n爲弟子。\n\n"
				"$n跪了下來向$N恭恭敬敬地磕了四個響頭，叫道：「師父！」\n",
				me, ob);

		me->recruit_apprentice(ob);
		ob->delete_temp("pending/apprentice");

		write("恭喜你新收了一名弟子！\n");
		family = ob->query("family");
		tell_object( ob, sprintf("恭喜您成爲%s的第%s代弟子。\n", family["family_name"],
			chinese_number(family["generation"]) ));

		return 1;
	

	} else {

		old_rec = me->query_temp("pending/recruit");
		if( ob==old_rec )
			return notify_fail("你想收" + ob->name() + "爲弟子，但是對方還沒有答應。\n");
		else if( objectp(old_rec) ) {
			write("你改變主意不想收" + old_rec->name() + "爲弟子了。\n");
			tell_object(old_rec, me->name() + "改變主意不想收你爲弟子了。\n");
		}

		me->set_temp("pending/recruit", ob );
		message_vision("\n$N想要收$n爲弟子。\n", me, ob);
		tell_object(ob, YEL "如果你願意拜" + me->name() + "爲師父，用 apprentice 指令。\n" NOR);
		return 1;
	}
}


int help(object me)
{
        write(@HELP
指令格式 : recruit [cancel]|<對象>
 
這個指令能讓你收某人爲弟子, 如果對方也答應要拜你爲師的話.
 
HELP
        );
        return 1;
}
