// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	mapping skill;
	int cost;

	if( me->is_fighting() )
		return notify_fail("你無法在戰鬥中專心下來研讀新知！\n");

	if(!arg || !objectp(ob = present(arg, me)) )
		return notify_fail("你要讀什麼？\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("你無法從這樣東西學到任何東西。\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("你是個文盲，先學學讀書識字(literate)吧。\n");

	message("vision", me->name() + "正專心地研讀" + ob->name()
		+ "。\n", environment(me), me);

	if( (int)me->query("combat_exp") < skill["exp_required"] ) {
		write("你的實戰經驗不足，再怎麼讀也沒用。\n");
		return 1;
	}

	notify_fail("以你目前的能力，還沒有辦法學這個技能。\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	cost = skill["sen_cost"] + skill["sen_cost"] 
		* (skill["difficulty"] - (int)me->query("int"))/20;
	if( (int)me->query("sen") < cost ) {
		write("你現在過於疲倦，無法專心下來研讀新知。\n");
		return 1;
	}

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
		write("你研讀了一會兒，但是發現上面所說的對你而言都太淺了，沒有學到任何東西。\n");
		return 1;
	}

	me->receive_damage("sen", cost);

	if( !me->query_skill(skill["name"], 1) )
		me->set_skill(skill["name"], 0);
	me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+1);
	write("你研讀有關" + to_chinese(skill["name"]) + "的技巧，似乎有點心得。\n");
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: study <物品名稱>

這個指令使你可以從祕笈或其他物品自學某些技巧,
但前提是: 你不能是個『文盲』。

see also : learn
HELP
   );
   return 1;
}
