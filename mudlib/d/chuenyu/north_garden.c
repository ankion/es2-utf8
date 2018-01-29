inherit ROOM;

void create()
{
        set("short", "北花園");
        set("long", @LONG
你站在黑松城堡的東花園裏。花園裏長滿了各式各樣奇花異草。
再通向北面的路被一塊巨石(rock)堵死。再往南則是雄偉的黑松閣。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "south" : __DIR__"west_blackge",
          ]));
          set("objects", ([
          __DIR__"npc/smallgardener" : 2,
          ]) );
          
          set("item_desc", ([
          "rock" : "這是一塊千斤巨石，阻住了通向北面的路。\n",
          ]));
          
          
          set("outdoors", "chuenyu");
          
          setup();
}
                  