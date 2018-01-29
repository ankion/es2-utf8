// Room: /d/oldpine/clearing.c

inherit ROOM;

void create()
{
	set("short", "林間空地");
	set("long", @LONG
這是一塊林間空地，四周的樹木花草像是被人修剪過一般，環繞著
空地圍成一個整齊的圓形，空地中央一株巨大的松樹(pine)像平地上撐
起一把大傘，樹上針葉茂密得遮去了大半的陽光，空地四周有三條小路
分別通往東、西、南三個方向，往南的小路旁豎著一個牌子(sign)。
LONG
	);
	set("item_desc", ([
		"pine": "一株又高又大的松樹，當你擡頭往上看的時候似乎有個人影\n"
				"在樹梢之間移動，不過也許\是風吹動所造成的錯覺。\n",
		"sign": "「官府告示：此處常有歹人出沒。」\n"
	]) );
	set("exits", ([
		"west" : "/d/oldpine/npath3",
		"north" : "/d/oldpine/spath1",
		"east" : "/d/oldpine/epath1"
]));

	setup();
}

void init()
{
	add_action("do_climb", "climb");
	if( this_player() ) {
		tell_room(__DIR__"tree1", this_player()->name() + "往樹下走了過來。\n");
	}
}

int do_climb(string arg)
{
	if( arg!="pine" ) return 0;

	message_vision("$N手腳並用，敏捷地爬上了空地中央的大松樹。\n",
		this_player());

	tell_room(__DIR__"tree1", this_player()->name() + "從樹下爬了上來。\n");
	this_player()->move(__DIR__"tree1");

	return 1;
}

int valid_leave(object me, string dir)
{
	tell_room(__DIR__"tree1",
		"樹下的" + me->name() + "往" + to_chinese(dir) + "離開了。\n");
	return 1;
}
