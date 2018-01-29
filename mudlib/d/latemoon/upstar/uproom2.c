
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "翠湘閣");
	set("long", @LONG
這是晚月莊的舞曲步法研究室, 名曰「翠湘」。牆上刻畫著各種
基本步法與一些詩詞曲賦。在每一位美女圖的姿態形體之中，那種翩
然起舞的曼妙舞姿，含蘊許多珍貴奇妙的舞步。你可以看到幾位師姐
一起走著奇特的步法，正在試著模擬這些舞步，一邊低頭沉思要如何
運用，十分的投入。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"upstar4",

]));

    set("objects", ([
        __DIR__"npc/shinfun" : 1,
    ]) );
    create_door("south","木門","north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
