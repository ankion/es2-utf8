// Room: /d/village/road9.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "青石小路");
	set("long", @LONG
兩隻小燕子落到柳枝上，嘰嘰喳喳叫個不停，它們的家可能在附近。
在小路的西面是一片綠油油的稻田，幾個農民在田間忙碌；東面是地主田
老財的宅院，難得一個地主的房子並不是特別奢華，只有三間屋子。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"road8",
  "west" : __DIR__"field",
  "east" : __DIR__"lordhouse1",
]));
	create_door("east","田老財家大門","west",DOOR_CLOSED);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
