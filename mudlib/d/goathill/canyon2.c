// Room: /d/goathill/canyon2.c

inherit ROOM;

void create()
{
	set("short", "峽谷");
	set("long", @LONG
你現在正走在一條狹長的深谷之中，東西兩面都是高不可攀的峭壁
，往南沿著谷底一條乾涸的山澗可以通往峽谷的出口，北邊的峭壁從這
裏斜斜向上宛如從天上掉下來倒插進地面，形勢更是危峻，連天空都被
北邊的峭壁遮去了七、八分。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"canyon3",
		"southup" : __DIR__"canyon1",
]));

	setup();
	replace_program(ROOM);
}
