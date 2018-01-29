// Room: /d/snow/guestroom.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
這裏是一間佈置得相當雅緻的廂房，從窗子可以看到北邊的天井跟
南邊的庭園中各式各樣的奇花異草，以及他們所帶來的淡淡香氣，廂房
的東面牆上還掛著一幅仕女圖(painting)，畫中是一位宮裝美婦，往西
是通往天井的出口。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/snow/inneryard",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
