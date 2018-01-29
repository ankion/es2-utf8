// Room: /d/chuenyu/croad2.c

inherit ROOM;

void create()
{
	set("short", "路口");
	set("long", @LONG
這裏是個交叉路口，過往行人很多。路邊有一個茶館，是供行
人歇息的地方。向南是通往京師的北驛道，北方可見陰森的黑松山。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"sunnyroad",
  "south" : __DIR__"croad1",
]));
	set("no_clean_up", 0);
	set("outdoors", "chuenyu");

	setup();
	replace_program(ROOM);
}
