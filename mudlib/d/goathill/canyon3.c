// Room: /d/goathill/canyon3.c

inherit ROOM;

void create()
{
	set("short", "峽谷");
	set("long", @LONG
你現在正走在一條峽谷的谷底，這裏的峭壁斜度之大讓你膽顫心驚
，只消有人在這裏一聲大喝將上面的土石震了下來，只怕立刻就得被活
埋，東邊的峭壁上有一個黑漆漆的洞穴，裏面似乎有什麼東西蠕蠕而動
，峽谷往西南和西北兩邊各有狹窄的出口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"cavern1",
		"southwest" : __DIR__"canyon2",
]));

	setup();
	replace_program(ROOM);
}
