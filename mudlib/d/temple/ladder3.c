// Room: /d/temple/ladder3.c

inherit ROOM;

void create()
{
	set("short", "石英岩石階");
	set("long", @LONG
你正走在一道長長的石英岩階梯上, 階梯的兩側種植著一排高聳
的松樹。雪亭鎮就在西邊不遠的山下, 你隱約還能聽到從鎮上傳來的
話語聲。階梯從這裏彎向北邊。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"ladder2",
  "westdown" : __DIR__"ladder4",
]));
	set("no_clean_up", 0);
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
