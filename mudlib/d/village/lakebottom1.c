// Room: /d/village/lakebottom1.c

inherit ROOM;

void create()
{
	set("short", "水下巖洞");
	set("long", @LONG
這個巖洞中全都是冰，冰的色澤純正潔白，很象是北極的玄冰，卻不
知怎麼會在這裏出現。四周氣溫極低，陣陣寒冷襲來，常人難以站立片刻。
在玄冰上面長着發光的藻類植物，所以從入口看去非常明亮。剛纔進入巖
洞的入口處又迅速地結了一層薄冰，奇怪的是水壓並沒有把它壓破。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "westup" : __DIR__"lakebottom2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
