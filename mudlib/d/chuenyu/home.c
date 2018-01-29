inherit ROOM;
#include <room.h>
void create()
{
        set("short", "劉家小房");
        set("long", @LONG
這是一所很破舊的木屋。每當山風吹來，都會發出“吱吱呀呀”
的聲音。南側是一個小小的廚房。木屋的後面是一個精巧的花園，花
園裏穿來陣陣打鬧之聲。一個翠綠的小草坪就在西面。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"smallstorage",
          "north" : __DIR__"littlegarden",
            "west" : __DIR__"smallyard",
              "southwest" : __DIR__"dustyroad3",
              ]));
              
              create_door("southwest", "木門", "northeast", DOOR_CLOSED);
              
              
              set("objects", ([
              __DIR__"npc/oldliu" : 1,
                      ]) );
                      
              setup();
}
