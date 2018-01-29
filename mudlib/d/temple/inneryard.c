// Room: /u/k/karrimor/temple/inneryard.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
你正站在靈心觀的天井裏, 這裏種植著一些花草樹木, 在西北角
落裏有著一口水井。北邊就是供俸茅山派歷代掌門人的地方, 南邊則
是一面牆, 牆的另一側就是大殿。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
     "north" : __DIR__"corridor5",
     "west" : __DIR__"corridor6",
     "east" : __DIR__"corridor7",
]));

    set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/little_taoist2" : 1,
    ]) );
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
