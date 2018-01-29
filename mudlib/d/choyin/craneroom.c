inherit ROOM;

void create()
{
        set("short", "樹冠");
        set("long",@LONG
古樹果非尋常之物，樹冠白霧升騰，上接霄漢，如仙境一般，讓人流連忘返...
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"guyehill",
        ]));
        set("objects", ([
                __DIR__"npc/crane" : 4,
                      ]) );

        setup();
        replace_program(ROOM);
} 
