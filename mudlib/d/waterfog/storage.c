// Room: /d/waterfog/storage.c

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
這裏是一間柴房，一捆一捆劈好的柴薪都整齊地堆放在柴房北側，
留下一條通道通往東邊僕役的臥室。往南可以回到水煙閣的西側廳。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"weststair",
		"east" : __DIR__"servroom",
	]) );

    set("objects", ([
		__DIR__"npc/servant" : 2
	]) );

	setup();
	replace_program(ROOM);
}
