// Room: /u/cloud/rich.c

inherit ROOM;

void create()
{
	set("short", "張百萬家");
	set("long", @LONG
你現在正站在張百萬家裏
    靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"m_house",
  "south" : __DIR__"eroad3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/room_gua" : 5,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
