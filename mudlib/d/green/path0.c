// Room: /d/green/path0.c

inherit ROOM;

void create()
{
	set("short", "小路的盡頭");
	set("long", @LONG
小路到了這裏以後往北變得很不明顯, 往南還可以依稀看到村子的
入口, 路的四周長滿了雜草和小樹之類的, 看來相當的荒涼. 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"north" : "/d/green/cave0",
  "south" : "/d/green/path1",
]));
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
