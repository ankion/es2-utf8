// Room: /d/snow/herbshop.c

inherit ROOM;

void create()
{
	set("short", "桑鄰藥鋪");
	set("long", @LONG
這裏是一間規模不小的藥鋪，奇怪的是，在這裏你聞不到一絲藥鋪
應有的藥味，有的只是一股淡淡的檀香，令人覺得心曠神怡，藥鋪的櫃
臺就在店鋪靠北的一面，櫃檯後是一個巨大的藥櫃(cabinet)， 上面的
小抽屜只怕有七、八百個之多，但是全部沒有貼標籤，藥鋪的出口在東
邊，櫃檯上貼著一張發黃的紙片(sign)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
		"cabinet" : @TEXT
一座巨大的杉木藥櫃，從它暗紅色的紋理跟幾處磨得發亮的痕跡，
這個藥櫃年代想必相當久遠了，有一點很特殊的是，藥櫃和牆壁似乎貼
得非常緊密，看不出絲毫縫隙。
TEXT
		,
		"sign": "紙片上寫著：價目表請用 list 向掌櫃查詢。\n",
]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"mstreet3",
	]));
	set("objects", ([
		__DIR__"npc/herbalist": 1,
		__DIR__"npc/woodcutter": 1,
	]) );

	setup();
	replace_program(ROOM);
}
