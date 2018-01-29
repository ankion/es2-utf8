// /d/city/shangshu/road3

inherit ROOM;

void create()
{
        set("short", "花園小徑");
        set("long",@LONG
這裏是尚書府的花園小徑。小徑的南方就是花園，陣陣花香隨風
飄過來，使人精神大振。廚房在小徑的東面，而往南則去往尚書府的
庭院。
LONG
        );

        set("exits", ([
		"north":	__DIR__"yuan",
		"south":	__DIR__"huayuan",
		"east":		__DIR__"chufang",
                ]));

        set("outdoors", "city");

 	setup();
        replace_program(ROOM);
}

