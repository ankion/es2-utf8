// /d/city/street4

inherit ROOM;

void create()
{
        set("short", "京師西街");
        set("long", @LONG
你現在正走在京師的街道上。東邊是進出紫禁城的午門，西邊則
是當朝地位顯赫的相國的府宅，而北邊不遠處“太白酒樓”的喧譁聲
依稀可聞。
LONG
        );

        set("exits", ([
                "east":         __DIR__"wumen",
                "west" :        __DIR__"xiangguo/gate",
                "north" :       __DIR__"street5",
                ]));

	set("objects", ([
		__DIR__"npc/walker":	1,
		__DIR__"npc/trader":	1,
		]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

