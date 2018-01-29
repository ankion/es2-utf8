// /d/city/street6

inherit ROOM;

void create()
{
        set("short", "京師西街");
        set("long", @LONG
你現在正走在京師的街道上。往東走便是紫禁城的後門--神武門
，南面似乎有一家酒樓，酒肉的香味一陣陣飄來。北邊是一個廢園，
據說裏面經常鬧鬼，所以沒人敢去。
LONG
        );

        set("exits", ([
                "east":         __DIR__"shenwumen",
                "south" :       __DIR__"street5",
		"west":         __DIR__"cloth",
                "north" :       __DIR__"feiyuan",
                ]));
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

