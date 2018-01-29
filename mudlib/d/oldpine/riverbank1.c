// Room: /d/oldpine/riverbank1.c

inherit ROOM;

void create()
{
	set("short", "山澗之中");
	set("long", @LONG
你現在正站在一條山澗中的岩石上，幾股泉水正從你腳邊流過，水
花濺得四處飛散，南邊是一個深不見底的水潭(lake)，兩邊的山壁看起
來又高又陡，看來要爬上岸邊實在很不容易，你的北方有一座小石橋高
高地跨過兩邊的山壁，可是橋的高度太高，即使是輕功絕頂的高手也躍
不上去。
LONG
	);
        set("item_desc", ([
            "lake":
                   "這是一個死水潭，潭水已經發綠，散發出陣陣的腥味。\n"
         ]) );

	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/oldpine/riverbank2",
  "south" : __DIR__"lake"
]));
	set("outdoors", "oldpine");
	set("resource/water", 1);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	if( !arg || arg!="cliff" ) return 0;

	message_vision("$N一付不信邪的表情，開始小心翼翼地攀著石壁爬了上去。\n",
		this_player() );
	this_player()->move(__DIR__"cliff1");

	return 1;
}

