// apprentice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_app;
	mapping family, skills;
	int i;
	string *skname;

	if( !arg ) return notify_fail("指令格式：apprentice [cancel]|<對象>\n");

	if( arg=="cancel" ) {
		old_app = me->query_temp("pending/apprentice");
		if( !objectp(old_app) )
			return notify_fail("你現在並沒有拜任何人爲師的意思。\n");
		write("你改變主意不想拜" + old_app->name() + "爲師了。\n");
		tell_object(old_app, me->name() + "改變主意不想拜你爲師了。\n");
		me->delete_temp("pending/apprentice");
		return 1;
	}

	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("你想拜誰爲師？\n");

	if( !living(ob) ) return notify_fail("你必須先把" + ob->name() + "弄醒。\n");

	if( ob==me ) return notify_fail("拜自己爲師？好主意....不過沒有用。\n");

	if( me->is_apprentice_of(ob) ) {
		message_vision("$N恭恭敬敬地向$n磕頭請安，叫道：「師父！」\n", me, ob);
		return 1;
	}

	if( !mapp( ob->query("family") ) )
		return notify_fail(ob->name() + "既不屬於任何門派，也沒有開山立派，不能拜師。\n");

	// If the target is willing to recruit us already, we do it.
	if( (object)ob->query_temp("pending/recruit") == me ) {

		if( (string)me->query("family/family_name") != (string)ob->query("family/family_name") ) {
			message_vision(
				"$N決定背叛師門，改投入$n門下！！\n\n"
				"$N跪了下來向$n恭恭敬敬地磕了四個響頭，叫道：「師父！」\n\n",
				me, ob);
			me->set("score", 0);
			me->add("betrayer", 1);
		} else
			message_vision(
				"$N決定拜$n爲師。\n\n"
				"$N跪了下來向$n恭恭敬敬地磕了四個響頭，叫道：「師父！」\n\n",
				me, ob);

		ob->recruit_apprentice(me);
		ob->delete_temp("pending/recruit");

		tell_object(ob, "恭喜你新收了一名弟子！\n");
		family = me->query("family");
		printf("恭喜您成爲%s的第%s代弟子。\n", me->query("family/family_name"),
			chinese_number( me->query("family/generation")));

		return 1;
	
	} else {

		old_app = me->query_temp("pending/apprentice");
		if( ob==old_app )
			return notify_fail("你想拜" + ob->name() + "爲師，但是對方還沒有答應。\n");
		else if( objectp(old_app) ) {
			write("你改變主意不想拜" + old_app->name() + "爲師了。\n");
			tell_object(old_app, me->name() + "改變主意不想拜你爲師了。\n");
		}

		message_vision("$N想要拜$n爲師。\n", me, ob);
		me->set_temp("pending/apprentice", ob );
		if( userp(ob) ) {
			tell_object(ob, YEL "如果你願意收" + me->name() + "爲弟子，用 recruit 指令。\n" NOR);
		} else 
			ob->attempt_apprentice(me);
	
		return 1;
	}
}


int help(object me)
{
        write(@HELP
指令格式 : apprentice [cancel]|<對象>
 
這個指令能讓你拜某人爲師，如果對方也答應要收你爲徒的話，就會立即行
拜師之禮，否則要等到對方用 recruit 指令收你爲弟子才能正式拜師。

請注意你已經有了師父，又背叛師門投入別人門下，所有技能會減半，並且
評價會降到零。

如果對你的師父使用這個指令，會變成向師父請安。
 
請參考相關指令 expell、recruit
HELP
        );
        return 1;
}
