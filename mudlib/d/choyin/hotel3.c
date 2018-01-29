// Room: /d/choyin/hotel3.c

inherit ROOM;

void create()
{
	set("short", "福林酒樓");
	set("long", @LONG
這裏是福林酒樓的客房，住的都是一些從外地來的富商大賈，爲了
預防宵小盜竊財物，福林酒樓的湯掌櫃特別僱請了許多武師擔任守衛的
工作，往下可以回到二樓。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"hotel2",
	]));
	set("objects", ([
		__DIR__"npc/guard": 3
	]) );

	setup();
	replace_program(ROOM);
}
