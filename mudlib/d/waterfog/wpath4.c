// Room: /d/waterfog/wpath4.c

inherit ROOM;

void create()
{
	set("short", "白石階梯");
	set("long", @LONG
你現在正走在一道依著山壁而建的白石階梯上，隨著階梯越爬越高
，從這裏已經可以望見西面山頂上豎立在虹臺中央的「擎天柱」，階梯
從這裏轉向西北坡度較緩的山腰，你的東邊是一個深不見底的深谷，隔
著深谷可以望見對面不遠處的水煙閣。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/waterfog/wpath3",
  "north" : "/d/waterfog/wpath5",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
