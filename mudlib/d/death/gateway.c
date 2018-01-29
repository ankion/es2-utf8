// Room: /d/death/gateway.c

inherit ROOM;

void create()
{
	set("short", "酆都城門");
	set("long", @LONG
你現在來到一座黑色城樓之前，城樓上刻著三個大字：酆都城。往
南不遠處有一座橋，橋上鬼影幢幢，但是卻聽不到半點聲音，往北走進
城樓只見一片黑漆漆的，只有少許暗紅色的火光若隱若現地閃爍著。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : "/d/death/road1",
		"south" : "/d/death/gate",
	]));
	set("objects", ([
		__DIR__"npc/bgargoyle": 1
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;

	if (dir == "south") {
		return notify_fail("一個空洞的聲音在你耳邊響起....\n"+
			       "沒有回頭路了!\n");
	}
	else return 1;
}


