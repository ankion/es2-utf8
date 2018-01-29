// Room: /d/city/shenwumen.c

inherit ROOM;

void create()
{
        set("short", "神武門");
        set("long", @LONG
你來到紫禁城的北門--神武門。南向的大門通向紫禁城，但這門
很少開。門上纏着大鐵鏈，還有士兵把守。往北走是皇家祭壇，不是
一年一度祭天時那總很冷清。東西向的道路分別通向京師東，西路。
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"jitan",
//		"south":	__DIR__"zijincheng",
		"east":		__DIR__"street1",
		"west":		__DIR__"street6",
		]));

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

