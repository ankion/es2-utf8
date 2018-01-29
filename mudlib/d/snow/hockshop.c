// Room: /d/snow/hockshop.c

#include <room.h>

inherit HOCKSHOP;

void create()
{
	set("short", "豐登當鋪");
	set("long", @LONG
這是一家中等規模的當鋪，老舊的櫃檯上放著一張木牌(sign)，屋
裏的光線不是很亮，往東的出口被一塊藍色布簾遮著，上面有「非請莫
入」的字樣，西邊有一扇木雕門(door)通往大街。
LONG
	);
	set("item_desc", ([
		"sign": @TEXT
本當鋪財力雄厚，童叟無欺，歡迎惠顧，絕對保密。
客倌可以在這裏典當(pawn)、賣斷(sell)各種貨物，銅錢、銀兩、黃金一概通用。
要贖回(retrieve)典物，請保持當票完整。
TEXT
	]) );
	set("exits", ([
		"west" : __DIR__"mstreet3",
		"east" : __DIR__"hockshop2",
	]));
//	set("objects", ([
//		CLASS_D("beggar") + "/master" : 1,
//	]) );

	setup();

	create_door("west", "木雕門", "east", DOOR_CLOSED);
}
