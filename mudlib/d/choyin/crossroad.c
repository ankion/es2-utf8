// Room: /d/choyin/crossroad.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
這裏是昌平街跟承安街的交叉路口，往南就是喬陰縣城的南門，往
北不遠處則是衙門的所在地，喬陰縣到了這裏顯得格外安靜，路人大多
沈默地走著，不敢大聲喧譁，和城東的花花世界相比，這裏顯得寧靜許
多。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"s_gate",
		"north" : __DIR__"court1",
		"east" : __DIR__"s_street5",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
