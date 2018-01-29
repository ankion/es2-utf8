// Room: /d/oldpine/spath3.c

inherit ROOM;

void create()
{
	set("short", "下坡道");
	set("long", @LONG
這是一條筆直的坡道，北高南低，道路兩旁長滿了許多松樹，從鬆
林間隱約可以聽到東邊傳來流水的聲音。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"spath4",
  "south" : __DIR__"spath2",
]));
	set("no_clean_up", 0);
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
