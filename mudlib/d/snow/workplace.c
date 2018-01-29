#include <dbase.h>
#include <room.h>

inherit ROOM;
 
string look_sign ();

void create ()
{
	set ("short","穀物加工廠");
	set ("long", @LONG
這是一間穀物加工廠，這裏是穀子脫殼成米的地方。米廠老闆是一個一
看就知道是十分精明的乾瘦的中年人，老是帶着一臉奸笑。你可以看到
許多人正在忙忙碌碌的工作着，門口掛著一塊牌子(sign)，往西是通往
雪亭鎮大街的大門。
LONG
	);
	
	set ("no_fight", 1);
	set ("item_desc", ([
		"sign": (:look_sign :),
	]) );

	set ("exits", ([
		"west"		: "/d/snow/mstreet2" ]));

	setup ();
}

void init ()
{
	add_action ("do_work", "work");
}

int do_work ()
{
	object me;
        object silver;

	me = this_player ();
	
        if((int)me->query("gin")<30 || (int)me->query("sen")<30)
                return notify_fail ("你的精神太差了,現在不能工作.\n");
	
	printf("
你辛苦的工作終於結束了，可人也累的要死。
老闆對你說：這是你的工錢。
");

	me->receive_damage( "sen", 30 );
	me->receive_damage( "gin", 30 );
 	silver=new(SILVER_OB);
	silver->set_amount(1);
	silver->move(me);
//	destruct(silver);
	return 1;
}
		
string look_sign ()
{
	return "告示
現在正緊缺人手，急需僱傭一批短工來幹活。
工作(work)一次，給工錢紋銀一兩。
";
}
