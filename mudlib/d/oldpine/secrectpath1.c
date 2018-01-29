// Room: /d/oldpine/secrectpath1.c

inherit ROOM;

void create()
{
	set("short", "祕密通道");
	set("long", @LONG
你現在正站在一個岩石通道之中，從南邊隱隱傳來嘩嘩的水聲，巖
壁上生著厚厚的青苔，一股惡臭從北邊傳來，像是什麼野獸，也許你該
回頭出去了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"path3",
  "south" : __DIR__"passage",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
