// Room: /d/sanyen/road1.c

inherit ROOM;

void create()
{
	set("short", "石板大道");
	set("long", @LONG
一條鋪著青石板的大道, 兩旁種植一排芍藥。北方就是大雄寶殿
, 一座上覆金瓦的雄偉建築, 屋檐的四個角落雕就著四隻栩栩如的金
龍, 屋檐下還各掛著一串金風鈴, 清風吹來, 發出陣陣清脆的鈴聲。
東邊有條小一點的石板路, 陣陣的藥香就從東邊傳來。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "north" : "/d/sanyen/temple",
            "south" : "/d/sanyen/door",
            "east" : "/d/sanyen/road2",
	]));

	create_door("north", "金門", "south");

	set("outdoors", "sanyen");
	set("objects", ([
		__DIR__"npc/monk" : 1
	]) );

	setup();
	replace_program(ROOM);
}
