// Room: /d/green/field1.c

inherit ROOM;

void create()
{
	set("short", "採石場的空地");
	set("long", @LONG
這是一片黃土空地，四周堆著一些切割整齊的大石塊和碎石。往東看
去就是採石場，高聳的石璧經過多年的採挖已經看不出原來的模樣了。往
南看去是一些矮小的房舍和儲存工具的地方，往西是村內的廣場，往北靠
近廣場的地方有一棟簡陋的民宅。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/green/field0",
  "south" : "/d/green/station1",
  "north" : "/d/green/house3",
]));
	set("objects", ([
	"/d/green/npc/kid1" : 1,
	]) );
	set("outdoors", "green");

	setup();
	replace_program(ROOM);
}
