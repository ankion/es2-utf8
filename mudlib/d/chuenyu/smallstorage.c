inherit ROOM;

void create()
{
        set("short", "廚房");
        set("long", @LONG
這是一個簡陋的小廚房。四壁已被油煙薰的分不出原來的顏色。
牆上掛滿了風乾了的滷肉，可是上面顯然有着被老鼠咬過的痕跡。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "north" : __DIR__"home",
          ]));
          set("objects", ([
          __DIR__"npc/rat" : 6,
          ]) );
          
          setup();
}
 
                  