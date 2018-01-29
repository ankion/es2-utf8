inherit ROOM;

void create()
{
        set("short", "花園");
        set("long", @LONG
這是劉老漢的小花園。花園裏有很多美麗的花朵。劉老漢
就是靠賣花來維持生計的。現在正是花開的大好季節，有很多
人在剪花。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"home",
        ]));
        set("objects", ([
        __DIR__"npc/flowergirl" : 5,
        ]) );
        set("outdoors", "chuenyu");
        setup();
}
                