inherit ROOM;

void create()
{
        set("short", "黑松閣東廳");
        set("long", @LONG
這是黑松堡主淳于懷太迎賓的東廳。整個大廳佈置的雍榮典雅。
向東和向西都是精心修剪過的花園。樓上則是淳于巨大的睡房。
偶爾有幾聲狗叫從東花園裏傳來。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
        "east" : __DIR__"east_garden",
          "south" : __DIR__"south_garden",
            "westup" : __DIR__"bedroom",
]));
                set("objects", ([
                __DIR__"npc/cleangirl" : 1,
                ]) );
                
                setup();
}

                                    