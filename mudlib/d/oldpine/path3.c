// Room: /d/oldpine/path3.c
#include <room.h>

inherit ROOM;

string look_stone();

void create()
{
	set("short", "祕密通道");
	set("long", @LONG
    你現在正站在一個陰森森的山洞之中, 一條昂首吐信的金銀花蛇,
爬伏在一塊突出的大青石(stone)上, 令人望而生畏, 也許你該回頭逃跑了。
LONG
	);

	set("item_desc", ([
		"stone" : (: look_stone :),
	]));

        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"secrectpath1",
        ]));

//	set("no_clean_up", 0);

	setup();
//	replace_program(ROOM);
}

string look_stone ()
{
	return ("一塊比人還高的鐘乳石, 雖然長滿了青苔, 但爬(climb)上去
應該不會太困難。\n");
}

void init()
{
	add_action ("do_climb", "climb");
}

int do_climb(string arg)
{
	if (!arg || arg != "up")
		return notify_fail("只有向上(up)爬一條道。\n");

	message_vision ("$N慢慢地攀上大青石。\n", this_player());
	this_player()->move (__DIR__"stone");
}
