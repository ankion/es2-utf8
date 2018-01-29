// Room: /d/sanyen/corridor.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你正走在一條長廊上, 兩旁種植著一排月桂樹。南邊的布幔後是
大殿, 北方則是後殿。東邊是個不小的廣場, 廣場上正曬著一些不知
名的藥草。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/sanyen/corridor1",
  "north" : "/d/sanyen/back_temple",
  "south" : "/d/sanyen/temple",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
