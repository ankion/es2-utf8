#include <room.h>
inherit ROOM;

void create()
{
        set("short", "膳房");
        set("long", @LONG
這是淳于堡主的用膳房。整個房間飄蕩着上等竹葉青的酒香和
令人垂灩欲滴的烤山豬的香氣。你似乎聽到你的肚子在“咕咕咕”
的叫了起來。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"bedroom",
        ]));
        set("objects", ([
        __DIR__"obj/pigmeat" : 3,
        __DIR__"obj/qiwine" : 3,
        __DIR__"npc/cook" : 1,
        ]) );
        
        
        create_door("north", "玉簾門", "south", DOOR_CLOSED);
        
        setup();
}

                