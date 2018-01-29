#include <room.h>

inherit ROOM;

void create()
{
	set("short", "晚月莊前庭");
	set("long", @LONG
一走入這個庭園，撲鼻而來的便是一股若有似無，但是又沁人心
脾的花香，庭園甚是寬敞，許多奇花異石錯落其間，顯是經過高手匠
人的精心佈置，西邊花叢間可看到主屋的屋角，一條石板小徑沿著假
山通往主屋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" :__DIR__"gate",
		"west" :__DIR__"latemoon1",
        "south" :__DIR__"park/yard1",
	]));
    set("outdoors", "latemoon");

	setup();
	replace_program(ROOM);
}

