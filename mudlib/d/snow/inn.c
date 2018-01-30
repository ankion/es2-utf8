// inn.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "飲風客棧");
	set("long", @LONG
你現在正站在雪亭鎮南邊的一家小客棧裏，這家客棧雖小，卻是方圓
五百里內最負盛名的一家，客棧的主人據說是一位雲遊四海的仙人，如果
你的福緣深厚的話，也許可以在這裏遇到他。除此之外，來自各地的旅人
都喜歡聚集在這裏交換旅途上的見聞，你也可以在這裏打聽到許多有趣的
消息。靠近門口的地方有一塊烏木雕成的招牌(sign)。
西北邊有一個紅木門(door)，門上泛著一層白色的光暈，一種令人感覺
很有力量，又很柔和的光芒。
LONG
	);

	/* This enables players to save this room as their startroom. */
	set("valid_startroom", 1);

	set("item_desc", ([
		"sign": (: look_sign :),
		"door": (: look_door, "northwest" :),
	]) );
	
	set("exits", ([
		"east"  : __DIR__"square",
		"up"		: __DIR__"inn_2f",
		"northwest"	: "/d/wiz/entrance" ]) );

    set("objects", ([
    __DIR__"npc/traveller" : 2,
    __DIR__"npc/waiter" : 1,
    ]) );

	create_door("northwest", "木門", "southeast", DOOR_CLOSED);

	setup();

	// To "load" the board, don't ever "clone" a bulletin board.
	// call_other( "/obj/board/common_b", "???" );
}

string look_sign(object me)
{
	if( wizardp(me) )
		return "招牌寫著：飲風客棧。旁邊一排小字：莊思啞題。\n";
	else
		return "招牌寫著：飲風客棧。\n";
}
