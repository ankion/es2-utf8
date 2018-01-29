//old_sword.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIG "古 劍" NOR, ({ "old sword", "sword"}));
	set_weight(800);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
行雲流水，如勁風之竹，氣聚於鋒，如晦如明，斯行於技，緩動而
瞬攻，乃徐如林，急如風，不動如山，侵略如火。
LONG
		);
		set("value", 100);
		set("material", "銅");
		set("skill", ([
		"name" :		"sword",
			"exp_required" :  2500,
            "sen_cost" : 20,
                    "difficulty" : 15,
            "max_skill" : 50
		]) );
        set("replica_ob", __DIR__"cola");
	}
}
		
