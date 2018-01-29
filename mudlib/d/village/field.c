// Room: /d/village/field.c

inherit ROOM;

void create()
{
	set("short", "稻田");
	set("long", @LONG
這是一片綠油油的稻田，稻子的長勢非常喜人，因爲北面就是玉螺湖，
所以稻田的灌溉很方便。從這兒向西能看到忘情谷那鬱鬱蔥蔥的山嶺，東
面能看到幾間高大房屋高出柳樹部分的屋檐。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
