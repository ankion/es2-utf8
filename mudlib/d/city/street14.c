// Room: /d/city/street14.c
inherit ROOM;
void create()
{
        set("short", "京師街道");
        set("long", @LONG
這裏是京師的大街上。西邊是京師的西一門，護國寺的僧人西
去取經必經此地。福緣好的話還可以看到幾個有道高僧路過。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "west"  :    __DIR__"westdoor1",
             "east"  :    __DIR__"street15",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

