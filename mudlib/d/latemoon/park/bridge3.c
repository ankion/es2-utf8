inherit ROOM;

void create()
{
   set("short", "朱欄板橋");
	set("long", @LONG
走在橋上，可以遠觀山坡幃脈，兩邊飛樓插空，雕飾□欄，隱
於亭園樹木之間；俯而視之，則清流瀉雪石磴穿雲。硃紅玉石爲欄
，環抱池沿，柳垂金線，桃吐丹霞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "south" :__DIR__"moon4",
       "northwest" :__DIR__"moon1",

]));

	setup();
	replace_program(ROOM);
}
