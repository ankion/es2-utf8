
inherit ROOM;

void create()
{
   set("short", "夾道");
	set("long", @LONG
你走在後廳內院的夾道上，莊內像這樣的走廊很多，你若沒有地
理概念很容易迷路。長長的走道中, 純金鑄成的長燈架上掛了一排飾
麗的宮燈! 入夜之後燈火輝煌! 十分美麗!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"guest1",
    "east" :__DIR__"twoc",
    "west" :__DIR__"two2",

]));

	setup();
	replace_program(ROOM);
}
