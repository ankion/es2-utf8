// Room: /d/sanyen/front_yard.c

inherit ROOM;

void create()
{
	set("short", "山煙寺前廣場");
	set("long", @LONG
這裏是山煙寺前的空地，平日僧人們就在這裏練武強身，空地四周
種了一排白楊樹，靠北邊的地方放了一堆用來鍛鏈膂力的磚頭，寺門就
在你的北邊, 東邊則是山門。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"door",
  "south" : __DIR__"gate",
]));
	set("outdoors", "sanyen");
        set("objects", ([
                __DIR__"npc/monk_guard":2,
        ]) );

	setup();
	replace_program(ROOM);
}
