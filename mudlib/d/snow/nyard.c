// Room: /d/snow/nyard.c

inherit ROOM;

void create()
{
	set("short", "書房");
	set("long", @LONG
這裏是一間整理得相當乾淨的書房，紅木桌椅上鋪著藍綢巾，顯得
十分考究，西面的立著一個書架，上面放著一排排的古書，往南走出房
門可以看到天井。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/snow/inneryard",
]));

	set("objects", ([
		__DIR__"npc/girl":1 ]) );

	setup();
	replace_program(ROOM);
}
