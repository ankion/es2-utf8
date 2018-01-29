// Room: /d/goathill/mroad4.c

inherit ROOM;

void create()
{
	set("short", "山路轉角");
	set("long", @LONG
你現在正走在一條崎嶇山路的轉角處，山路望東通往野羊山上，從
這裏可以望見東邊不遠處有一個石屋立在巖壁邊上，看起來像是岡哨或
什麼的，北邊的山壁有一個裂口(crack)，不過離地約有三到四丈， 往
南的山路是段陡峭的下坡，如果你要下山，大概就是這條路了。
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"mroad5",
		"southdown" : __DIR__"mroad3",
	]));
	set("objects", ([
		__DIR__"npc/bandit" : 3,
		__DIR__"npc/bandit_leader" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
