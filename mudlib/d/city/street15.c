// Room: /d/city/street15.c
inherit ROOM;
void create()
{
        set("short", "京師街道");
        set("long", @LONG
你來到京師的大街。北邊是護國寺的大門，寺內香菸繚繞。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
//             "north" :    __DIR__"templegate",
             "west"  :    __DIR__"street14",
             "east"  :    __DIR__"street7",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

