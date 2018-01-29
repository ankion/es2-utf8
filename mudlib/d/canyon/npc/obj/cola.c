inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIB"一瓶深藍色的可樂"NOR,({ "cola" }) );
	set("long", "這是一瓶只有在Void 才見的到的獎品，口渴使你忍不住想
喝他一口(drink)。\n");
	set("unit", "瓶");
	set("base_weight", 200);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object ob;

	if( !arg || arg != "cola") 
		return notify_fail("你要喝甚麼呢? \n");

	message_vision( MAG
 	"$N喝了口可樂,舔了舔嘴邊,似乎回味無窮.....\n"+HIR
 	"$N臉上露出詭異的表情....\n" NOR,this_player()  
 	); //end_message_vision
	message_vision(WHT"這瓶可樂被$N喝完了，$N隨手一丟，說也奇怪地就不見了。
				\n"NOR,this_player() );

    	
    	this_player()->set("water",this_player()->max_water_capacity());
	destruct(this_object());
	
	return 1;
}
