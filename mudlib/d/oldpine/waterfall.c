// Room: /d/oldpine/waterfall.c

inherit ROOM;

void create()
{
	set("short", "瀑布前");
	set("long", @LONG
你現在正站在瀑布前的一個小水潭裏，水潭大約深可及胸，淹不死
人，一條白練般的瀑布(waterfall)從數百丈高的懸崖上衝激而下，濺
得你全身溼透，水潭三面都被高聳的山壁(cliff)所包圍，只有南面沿
著一條山澗可以出去。
LONG
	);
	set("item_desc", ([
		"waterfall":
			"這個瀑布水勢並不是很大，但是高度卻極高，水珠濺在你的臉上\n"
			"打得隱隱生疼。你注意到瀑布後面似乎有什麼東西在發著光。\n",
		"cliff":
			"水潭四周的山壁都有數百丈高，想要爬上去「肯定」是休想。\n"
	]) );
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/oldpine/riverbank2",
]));
	set("resource/water", 1);
	setup();
	replace_program(ROOM);
}
