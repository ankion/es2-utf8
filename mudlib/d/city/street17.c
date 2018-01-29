// Room: /d/city/street17.c
inherit ROOM;
void create()
{
        set("short", "京師街道");
        set("long", @LONG
你來到京師的大街上。南邊是京師的南門，出了南門就可去南
方重鎮……南海鎮。北邊是天橋，人聲鼎沸。西邊是刑場，一個一
般人極少去的地方。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
/*             "west"   :    __DIR__"xingchang", */
             "north"  :    __DIR__"bridge",
             "south"  :    __DIR__"southdoor",]));
        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

