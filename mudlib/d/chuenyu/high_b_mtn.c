// Room: /d/chuenyu/high_b_mtn2.c

inherit ROOM;

void create()
{
        set("short", "花崗石街");
        set("long", @LONG
這是通往城堡的石街，整條石街全是用巨大的花崗岩砌成的。
單這條石路就足已表明城堡主人的富有和氣勢。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "up" : __DIR__"gate_castle",
          "east" : __DIR__"rope_bridge",
          ]));
          
          set("outdoors", "chuenyu");
          
          setup();
}
                  
