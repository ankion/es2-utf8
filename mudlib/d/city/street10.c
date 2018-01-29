// Room: /d/city/street10.c
inherit ROOM;
void create()
{
        set("short", "京師街道");
        set("long", @LONG
這裏是京師的大街。東邊是京師的東二門，一些剛進城的行人
坐在路邊休息，不時發出一陣鬨笑聲。往西就可以到京師中心了。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "east"   :    __DIR__"eastdoor2",
             "west"   :    __DIR__"street11",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

