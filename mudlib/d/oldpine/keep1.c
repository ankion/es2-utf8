// Room: /d/oldpine/keep1.c

inherit ROOM;

void create()
{
	set("short", "老鬆寨祕密入口");
	set("long", @LONG
這裏只見一個木頭搭成的大門，門框上掛著四、五的不知道是什麼
動物的頭骨跟一些鐵鏈，外面再鋪上一層乾枯的松枝，在這樣一個森林
裏還真不容易發覺。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/oldpine/pine2",
  "east" : "/d/oldpine/keep2",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/oldpine/npc/bandit_guard" : 4,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
