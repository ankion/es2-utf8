// Room: /d/choyin/tomb3.c

inherit ROOM;

void create()
{
	set("short", "樹王墳內部");
	set("long", @LONG
這裏是樹王墳樹洞的內部，你在這裏可以聞到一股濃郁的檀香，奇
怪的是，這棵大樹並不是檀木，卻不知這股香味從哪裏來？往南的出口
通往樹洞的另一端。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"tomb1",
	]));
	set("objects", ([
		__DIR__"obj/chest": 1
	]) );

	setup();
	replace_program(ROOM);
}
