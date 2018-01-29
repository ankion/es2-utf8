// Room: /d/waterfog/entrance.c

inherit ROOM;

void create()
{
	set("short", "水煙閣正門");
	set("long", @LONG
這裏是水煙閣的正門，一股沁人心脾的檀香使你精神爲之一振，正
門共分三進，全部都是上等的檀木雕成，最裏的門上懸著一塊匾額，上
面龍飛鳳舞地寫著幾個大字，可是你全然看不出到底是什麼字。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"frontyard",
		"west" : __DIR__"westhall",
		"east" : __DIR__"easthall",
		"north" : __DIR__"guildhall",
	]));
	set("objects", ([
		__DIR__"npc/guard": 2
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir != "north" || wizardp(me) ) return 1;
	if( me->query_temp("weapon")
	&&	present("waterfog guard", this_object()) ) {
		message("vision", "水煙閣武士喝道：慢著，進水煙閣，先放下你的兵刃！\n", this_object());
		return notify_fail("水煙閣武士擋住了你的去路。\n");
	}
	return 1;
}
