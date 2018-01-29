// Room: /d/oldpine/cliffside.c

inherit ROOM;

void create()
{
	set("short", "林間....不....懸崖邊");
	set("long", @LONG
你現在正站在一個松樹林間的小空地上，你的北邊、東邊、南邊都
是茂密的松樹，唯獨西邊是個懸崖(cliff)，當你探頭一看，立刻不由
自主地倒抽一口涼氣，在這裏可得千萬小心，一不小心跌了下去肯定是
粉身碎骨。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
///  "south" : "/d/oldpine/pine2",
  "north" : "/d/oldpine/pine1",
///  "east" : "/d/oldpine/pine1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "cliff" : "你定下心神一看，其實這個懸崖沒有想像中那麼恐怖，也許\還
可以從這裏爬下山澗，只是這世界上大概沒有這種白癡願意幹
這種傻事吧。
",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
