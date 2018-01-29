// Room: /d/choyin/s_street3.c

inherit ROOM;

void create()
{
	set("short", "福林大街");
	set("long", @LONG
這裏是喬陰縣城的福林大街，往北是一座高臺，臺上便是著名的「
樹王墳」，打從這裏往南就是喬陰縣最熱鬧的街道，接上來往的行商販
子也最多，你的東邊和西邊都是石板空地，平常的市集便在此處，遇到
賽會節慶這裏更是擠得水泄不通，福林大街往南是個路口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"s_street2",
  "north" : __DIR__"tree_tomb",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
