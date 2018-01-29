// Room: /d/waterfog/servroom.c

inherit ROOM;

void create()
{
	set("short", "僕役臥室");
	set("long", @LONG
這裏是在水煙閣從事雜役的僕傭所住的臥室，房間相當寬敞，東西
向一張大通鋪最少可以睡二、三十人，東首一張大炕(bed)是冬天才用
的，因爲有不少僕役回家過冬，所以比牀鋪稍小，北邊開了幾扇窗子，
南邊則是擺放僕役私物的櫥櫃。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"storage",
    ]) );

	setup();
	replace_program(ROOM);
}
