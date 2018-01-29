#include <room.h>

inherit ROOM;

void create()
{
   set("short", "內廳穿堂");
	set("long", @LONG
通過『 垂花門 』便是往後院。垂花門爲男女之門限，古來女
人就有「大門不出，二門不邁」的諺語，於是二門堪稱爲男女門限
。後院爲莊內女弟子廂房，與湘園。東面一扇小門，爲莊內更衣沐
浴的小花池。更是嚴禁外人胡亂闖入。
LONG
	);
    set("exits", ([
     "north" :__DIR__"corridor7",
     "east" :__DIR__"bathroom1",
     "south" : "/d/latemoon/miroom2",
    ]));
    set("objects", ([
        __DIR__"npc/shaoin" : 1,
    ]) );

     create_door("north","垂花門","south", DOOR_CLOSED);
     create_door("east","小簾門","west", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
