// Room: /d/sanyen/gate.c

inherit ROOM;

void create()
{
	set("short", "山煙寺山門");
	set("long", @LONG
這裏是往山煙寺的山門，山煙寺在你的西面不遠，由於寺中的老方丈
玄智和尚醫術通神，不少受過恩惠的各地富豪將山煙寺修整得金碧輝煌，
莊嚴雄偉，因此山煙寺規模雖然不及京城的白象禪院，但是名氣卻是
大得多了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"sroad2",
		"north" : __DIR__"front_yard",
        "west" : __DIR__"tunnele",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/greeting" : 2,
	]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
