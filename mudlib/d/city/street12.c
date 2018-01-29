// Room: /d/city/street12.c
inherit ROOM;
void create()
{
        set("short", "京師街道");
        set("long", @LONG
這裏是京師的大街，青石鋪道，街面很乾淨。東邊是京師的熱
鬧場所天橋，來到京師可不能不去哦。南邊是京師的刑場，逢上處
決一些重要的犯人的時候，那裏肯定是人山人海，不過平時人就少
得多了。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "east"   :    __DIR__"bridge",
             "west"   :    __DIR__"street13",]));
//             "south"  :    __DIR__"xingchang",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}
