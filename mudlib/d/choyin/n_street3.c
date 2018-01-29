// Room: /d/choyin/n_street3.c

inherit ROOM;

void create()
{
	set("short", "福林大街");
	set("long", @LONG
你現在正走在一條寬敞的大街上，街道往北邊筆直地延伸，南邊則
是一個隆起的石臺，你可以看見石臺前有塊石碑，上書「樹王墳」三個
大字，街道的東邊和西邊都是石板空地，圍繞著樹王墳成爲一個圓環，
許多小販客商都聚集在這裏交易買賣。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nw_street",
  "north" : __DIR__"n_street2",
  "south" : __DIR__"tree_tomb",
]));
	set("objects", ([
		__DIR__"npc/dumpling_seller": 1
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
