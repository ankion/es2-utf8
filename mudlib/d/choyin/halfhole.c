inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
這裏就是半山腰處的山洞。四壁空無一物，極爲荒涼......
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"guyehill",
                   ]));
        set("objects", ([
                __DIR__"obj/goldenrope" : 1,
               ]) );

        setup();
        replace_program(ROOM);
}

