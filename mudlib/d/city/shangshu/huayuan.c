// /d/city/shangshu/huayuan
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "花園");
        set("long",@LONG
尚書府的花園裏蒐集了許多名貴花卉。從洛陽的牡丹到揚州的瓊
花，你不能不驚詫於這裏的全來。四時的花卉競相開放着，發出沁人
的香味。從花園東行就是內宅，而西邊似乎有一間破屋。
LONG
        );

        set("exits", ([
		"north":	__DIR__"road3",
		"east":		__DIR__"neizhai",
		"west":		__DIR__"road4",
                ]));

	set("objects", ([
		__DIR__"npc/gardener":	1,
		]));

	create_door("east", "簾子", "west", DOOR_CLOSED);

	set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

