// Room: /d/goathill/mroad5.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
這裏是一段狹窄的山路，往東不遠處的巖壁邊上有一座石屋，路旁
生滿了及腰的長草，山風吹過一起一伏的有如波浪一般，南北兩邊有許
多大石，看起來倒是個埋伏的好地點，往西是一個山路的轉角。
LONG
	);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 3 */
		"northeast" : __DIR__"mroad6",
		"east" : __DIR__"slope1",
		"west" : __DIR__"mroad4",
]));

	setup();
	replace_program(ROOM);
}
