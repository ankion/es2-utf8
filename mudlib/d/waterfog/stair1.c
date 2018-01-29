// Room: /d/waterfog/stair1.c

inherit ROOM;

void create()
{
	set("short", "白石階梯");
	set("long", @LONG
你現在正走在一條長長的白石階梯上，這些建造階梯的白石出產於
東海濱的裂瓶山，距離此地有近千里之遙，而且雖然年代久遠，仍然可
以看得出所用的全部都是品質最好的「擬玉」石，可見這裏的主人必定
大有來頭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/d/waterfog/stair2",
  "southdown" : "/d/waterfog/sroad3",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
