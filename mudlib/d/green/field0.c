// Room: /d/green/field0.c

inherit ROOM;

void create()
{
	set("short", "小廣場");
	set("long", @LONG
這是一個小小的廣場，地上鋪著切割整齊的大石塊。廣場周圍有幾間
屋子，其中以正南邊那棟木屋最爲特別。往西是一條窄窄的小巷子，往東
則是連接著採石場的空地。中央有一棵大榕樹，像一座涼亭般地立在廣場
上。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/green/path8",
  "south" : "/d/green/house4",
  "north" : "/d/green/house2",
  "east" : "/d/green/field1",
]));

	setup();
	replace_program(ROOM);
}
