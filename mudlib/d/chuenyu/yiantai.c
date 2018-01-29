inherit ROOM;

void create()
{
        set("short", "陽臺");
        set("long", @LONG
這是一個小小的陽臺。從這裏你可以一直望到山腳。強勁
的山風吹在你身上，讓你感到份外的涼爽。真是一個好去處。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
         "south" : __DIR__"bedroom",
         ]));
         set("objects", ([
         __DIR__"npc/pigeon" : 2,
         ]) );
         
         set("outdoors", "chuenyu");
         setup();
}

                 