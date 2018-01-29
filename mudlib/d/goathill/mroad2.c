// Room: /d/goathill/mroad2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你現在正走在一條崎嶇的山路上，路面到處生滿了及膝的雜草叢，
顯示這裏已經有一段時間沒有車馬經過了，從這裏往北就是野羊山的地
界，野羊山有一座山寨，住著許多兇惡的盜匪，你最好繞道而行。
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"mroad3",
		"south" : __DIR__"mroad1",
]));

	setup();
	replace_program(ROOM);
}
