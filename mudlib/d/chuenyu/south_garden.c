inherit ROOM;

void create()
{
        set("short", "南花園");
        set("long", @LONG
你站在黑松城堡的南花園裏。花園裏長滿了各式各樣奇花異草。
再往北則是雄偉的黑松閣。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"east_blackge",
        ]));
        set("objects", ([
        __DIR__"npc/smallgardener" : 2,
        ]) );
        
        setup();
}
                