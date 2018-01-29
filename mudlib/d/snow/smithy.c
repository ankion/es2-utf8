// Room: /d/snow/smithy.c

inherit ROOM;

void create()
{
	set("short", "打鐵鋪子");
	set("long", @LONG
這裏是一間打鐵鋪子，從火爐中冒出的火光將牆壁映得通紅，屋子
的角落裏堆滿了各式鐵器的完成品或未完成品，像是鋤頭、鐵錘、鏟子
等，叮叮噹噹的聲音敲得滿屋子響。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/snow/mstreet2",
]));

	set("objects", ([
		"/d/snow/npc/smith": 1 ]) );
	setup();
	replace_program(ROOM);
}
