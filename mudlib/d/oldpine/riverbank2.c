// Room: /d/oldpine/riverbank2.c

inherit ROOM;

void create()
{
	set("short", "山澗之中");
	set("long", @LONG
你現在正站在一條山澗中的岩石上，一座小石橋正高高地從你的頭
頂橫跨過山澗兩邊的石壁(cliff)，一個瀑布就在你的北方不遠處，從一
處更高的懸崖上垂了下來。
LONG
	);
	set("item_desc", ([
		"cliff":
			"這裏的山壁比北邊高度稍低了點，但是對凡人而言想要爬上去仍然\n"
			"還有一段差距。\n"
	]) );
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/oldpine/waterfall",
  "south" : "/d/oldpine/riverbank1",
]));
	set("outdoors", "oldpine");
	set("resource/water", 1);

	setup();
	replace_program(ROOM);
}
