// Room: /d/city/street1.c

inherit ROOM;

void create()
{
        set("short", "京師東街");
        set("long", @LONG
這裏是京師東街的北段。往北走有一個大院子，院裏立着根老高
老高的旗杆，上書一個斗大的「鏢」字，隔很遠就可以看見。鏢局的
生意似乎很好，人絡繹不絕。西向是莊嚴的神武門。向南則去向尚書
府和午門。
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"biaoju",
		"south":	__DIR__"street2",
		"west":		__DIR__"shenwumen",
		]));

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

