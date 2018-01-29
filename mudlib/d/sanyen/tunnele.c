// Room: /d/sanyen/tunnele.c

inherit ROOM;

void create()
{
	set("short", "隧道口");
	set("long", @LONG
你走進了一個鑿穿山壁開成的隧道，東邊是隧道的出口，往西不遠
處也可以從這裏瞧見西邊的出口，一股硫磺的味道從隧道壁中傳來，想
必左近便有溫泉或是火山。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tunnel",
  "east" : __DIR__"gate",
]));

	setup();
	replace_program(ROOM);
}
