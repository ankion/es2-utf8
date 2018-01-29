// Room: /d/sanyen/sroad2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
這條山路到這裏轉了個彎，往東穿過一個山壁上鑿出來的隧道，往
南則順著山勢緩緩下山。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
 "east": __DIR__"sroad1",
 "north": __DIR__"gate",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
