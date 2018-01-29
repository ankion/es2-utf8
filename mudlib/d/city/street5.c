// /d/city/street5

inherit ROOM;

void create()
{
        set("short", "京師西街");
        set("long",@LONG 
你現在正走在京師的街道上，西邊是京師最有名的“太白酒樓”，
酒樓裏三教九流的人物都有，嘈雜聲不絕於耳。東邊緊鄰着紫禁城的
城牆(wall)。街道向南北方向延伸着。
LONG
        );

        set("exits", ([
		"west" :	__DIR__"jiulou",
		"south" : 	__DIR__"street4",
		"north" :	__DIR__"street6",
		]));
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

