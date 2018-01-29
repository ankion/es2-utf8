// Room: /d/sanyen/tunnel.c

inherit ROOM;

void create()
{
	set("short", "隧道");
	set("long", @LONG
你走進了一個鑿穿山壁開成的隧道，隧道也不甚長，約七、八丈左
右，西邊就是隧道的出口，隧道中你可以聞到一股硫磺的味道，想必左
近便有溫泉或是火山。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/latemoon/sroad5",
  "east" : __DIR__"tunnele",
]));

	setup();
	replace_program(ROOM);
}
