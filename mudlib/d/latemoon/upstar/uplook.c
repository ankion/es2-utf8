
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "觀景臺");
	set("long", @LONG
這是晚月莊的前堂樓觀景臺，站在臺前你可以看到整個莊院的  
佈局，瀚煙山美麗景色盡收眼裏。微微的山風輕拂你的臉龐，有種
說不出的輕爽。遠處山寺的鐘聲，飛鳥的鳴啼，與眼前的景色構成
一幅山林風光的風景畫。正下方是前院。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"upstarc",
    "jump" : "/d/latemoon/park/yard1",

]));

    set("objects", ([
        __DIR__"npc/bird" : 2,
    ]) );
    set("outdoors", "latemoon");
    create_door("west","樓門","east", DOOR_CLOSED);
    setup();
	replace_program(ROOM);
}
