// Room: /d/city/street2.c

inherit ROOM;

void create()
{
        set("short", "京師東街");
        set("long", @LONG
你走在京師東街的中段。這裏夾在紫禁城城牆與尚書府院牆之間
，南向的道路通向午門和尚書府的大門，而北方不遠處振遠總局的旗
杆依稀可見，令人隱隱約約地感到一種殺氣。
LONG
        );

	set("objects", ([
		__DIR__"npc/walker":	2,
		]) );

        set("exits", ([ 
		"north":	__DIR__"street1",
		"south":	__DIR__"street3",
		]));

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

