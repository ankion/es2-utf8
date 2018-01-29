#include <room.h>
inherit ROOM;

void create()
{
        set("short", "黑松閣西廳");
        set("long", @LONG
這是黑松堡主淳于懷太迎賓的西廳。整個大廳佈置的雍榮典雅。
向東是黑松閣的正廳，向西和向北都是精心修剪過的花園。樓上則是
淳于巨大的睡房。南面是一個小小的儲藏室。
LONG
        );
         set("exits", ([ /* sizeof() == 5 */
         "eastup" : __DIR__"bedroom",
           "east" : __DIR__"center",
             "west" : __DIR__"west_garden",
               "south" : __DIR__"storage",
                 "north" : __DIR__"north_garden",
                 ]));
          set("objects", ([
          __DIR__"npc/guard" : 2,
          ]) );
          
          create_door("south", "木門", "north", DOOR_CLOSED);
          
          setup();
}
                         