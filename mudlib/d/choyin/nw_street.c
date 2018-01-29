// Room: /d/choyin/nw_street.c

inherit ROOM;

void create()
{
	set("short", "石板空地");
	set("long", @LONG
這裏是樹王墳西北邊的石板空地，因爲樹王的根範圍太廣，因此樹
王墳周圍十幾丈都沒有辦法蓋房子，因此這裏鋪了石板，平時便當作百
姓散步休憩的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"w_street4",
  "south" : __DIR__"w_street3",
  "east" : __DIR__"n_street3",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
