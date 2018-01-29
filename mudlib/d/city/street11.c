// Room: /d/city/street11.c
inherit ROOM;
void create()
{
        set("short", "京師街道");
        set("long", @LONG
這裏是京師的大街。西邊是京師的熱鬧場所天橋，一些行人匆
匆往西走去。據說天橋的夜市也不差哦。南邊是一片民宅，炊煙繚
繞。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "west"   :    __DIR__"bridge",
	     "north"  :    __DIR__"boots",
             "east"   :    __DIR__"street10",
             "south"  :    __DIR__"house1",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

