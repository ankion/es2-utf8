//old_sword.c

#include <ansi.h>

inherit ITEM;
//inherit F_UNIQUE;

void create()
{
    set_name( "過招要旨", ({ "parrybook","pbook" }) );
	set_weight(800);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
這是一本介紹過招時如何拆招卸力的書籍。
對練武人來說是本不可多得的珍寶。
LONG
		);
		set("value", 100);
    		set("material", "paper");
		set("skill", ([
        		"name" :        "parry",
            		"exp_required" :  15000,
            		"sen_cost" : 30,
                    	"difficulty" : 25,
            		"max_skill" : 50
			]) );
        	set("replica_ob", __DIR__"cola");
		}
}
		
