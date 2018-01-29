// Room: /d/choyin/yamen_iner.c

inherit ROOM;

void create()
{
	set("short", "內廳");
	set("long", @LONG
內廳是老爺與好友敘話, 品茶, 吟詩, 作畫之所; 格外幽靜......
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yamen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
