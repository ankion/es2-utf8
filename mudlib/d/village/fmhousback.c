// Room: /d/village/fmhousback.c

inherit ROOM;

void create()
{
	set("short", "農舍後院");
	set("long", @LONG
在後院的左側有個豬圈，幾隻小白豬在裏面胡吃海塞，右面是一排雞
籠，兩個紅皮雞蛋落在雞籠後邊的槽裏。這村子的婦女經常把自家產的雞
蛋拿到京城去賣，去扯些花布或作件衣服。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"farmhouse1",
]));
	//set("no_clean_up", 0);
	set("objects", ([
		"/d/village/npc/woman1":1,	
		]) );
	setup();
	//replace_program(ROOM);
}
