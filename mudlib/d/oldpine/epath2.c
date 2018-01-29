// Room: /d/oldpine/epath2.c

inherit ROOM;

void create()
{
	set("short", "小石橋");
	set("long", @LONG
你現在正站在一座長滿青苔的古橋上，橋下是一條山澗，幾股清泉
在亂石之中向山下奔流，橋北邊不遠處有一個瀑布(waterfall) ，從山
壁上猶如一條白練般垂了下來，瀑布兩旁的石壁十分陡峭，高度和山澗
旁的松林相差了近三、四十丈。
LONG
	);
	set("item_desc", ([
		"waterfall":
			"這個瀑布從數百丈高的山壁上衝激而下，流入一個山澗底的小水潭\n"
			"，水潭兩邊的石壁垂下許\多的藤蔓(vine)，你注意到瀑布後面似乎\n"
			"有什麼東西在發著光。\n",
		"vine":
			"其中有一根藤蔓距離你比較近，你可以試著抓住(hold)藤蔓，看看\n"
			"能不能像泰山一樣蕩過去，看看瀑布後面有什麼？\n"
			"對了，提醒你一點，這座石橋下面是高約百丈的山澗深谷....。\n"
	]) );
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/oldpine/epath1",
  "east" : "/d/oldpine/epath3",
]));
	set("outdoors", "oldpine");

	setup();
}

void init()
{
	add_action("do_hold_vine", ({ "hold", "grab" }) );
}

int do_hold_vine(string arg)
{
	if( !arg || arg!= "vine" )
		return notify_fail("你要抓住什麼？\n");
	message_vision("$N爬上石橋的護欄，伸手往不遠處的一根藤蔓抓去....\n",
		this_player());
	if( random((int)this_player()->query_skill("dodge")) < 5 ) {
		message_vision("\n只聽見一聲殺豬般的慘叫，$N已經往山澗中墜了下去。\n\n", this_player());
		tell_room(__DIR__"waterfall",
			"你聽到有人高聲驚叫，一條人影從上方掉了下來，「撲通」一聲跌進潭中。\n");
		this_player()->move(__DIR__"waterfall");
	} else {
		message_vision("$N手腳俐落地攀附著藤蔓，慢慢地爬下山澗....。\n",
			this_player() );
		tell_room(__DIR__"passage",
			"忽然一條人影從南邊的簾幕穿了出來。\n");
		this_player()->move(__DIR__"passage");
	}
	return 1;
}

