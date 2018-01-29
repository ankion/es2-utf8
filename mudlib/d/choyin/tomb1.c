// Room: /d/choyin/tomb1.c

inherit ROOM;

void create()
{
	set("short", "樹王墳");
	set("long", @LONG
這裏是樹王墳內部的樹洞，由於這棵大樹實在太大，因此你站在樹
洞裏，一點也不覺得侷促，樹洞約有兩個人的高度那麼深，你可以攀附
粗糙的洞壁往上離開，東邊的樹根比較少，露出一些土層，北邊跟西邊
則是樹洞的另一端。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tomb3",
  "west" : __DIR__"tomb2",
  "up" : __DIR__"tree_tomb",
]));
	set("objects", ([
		__DIR__"npc/shadow": 3
	]) );

	setup();
	replace_program(ROOM);
}
