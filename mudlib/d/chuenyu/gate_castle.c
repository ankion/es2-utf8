#include <room.h>

inherit ROOM;

void create()
{
        set("short", "黑松淳于");
        set("long", @LONG
你站立在一座宏偉的城堡之前，城門(door)之上掛着一塊金匾。金匾上
龍飛鳳舞的寫着四個大字“黑松淳于”，金匾左下角剛勁草書落款：
“淳于懷太”，“壬子年一月十八日”。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "east" : __DIR__"east_castle",
          "west" : __DIR__"west_castle",
            "north" : __DIR__"trap_castle",
              "down" : __DIR__"high_b_mtn2",
]));
        set("outdoors", "chuenyu");
        
        create_door("north", "城門", "south", DOOR_CLOSED);
        
        setup();
}

void init()
{       object ob;
        int exp;
        if( interactive( ob = this_player()))
        {
        exp = ob->query("combat_exp");
        if(exp < 2000) {
        ob->move(__DIR__"high_b_mtn2.c");
//        message_vision(HIW"\n$N被黑松堡散出的強烈殺氣當了回來。\n\n" NOR, ob);
        message_vision("\n$N被黑松堡散出的強烈殺氣當了回來。\n\n" , ob);        }
         }
}
                                       