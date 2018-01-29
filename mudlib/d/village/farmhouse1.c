// Room: /d/village/farmhouse1.c

inherit ROOM;

void create()
{
	set("short", "農舍");
	set("long", @LONG
這間農舍內的擺設非常樸素，但十分井井有條。陽光順着窗縫撒在屋
角落裏的紡車上，桌上擺着泥作的玩具，特別是那泥老虎捏的形態生動活
潑，色彩逼真，旁邊還擺着一把木刀，可能都是父親作給小孩的玩具。一
張大牀的旁邊還有一張小牀。這屋的北面是農舍的後院，南邊出了屋就是
村裏的青石小路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fmhousback",
  "south" : __DIR__"road4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
