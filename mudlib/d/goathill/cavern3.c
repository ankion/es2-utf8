// Room: /d/goathill/cavern3.c

inherit ROOM;

void create()
{
	set("short", "巖穴");
	set("long", @LONG
這裏一片黑漆漆，你必須全靠摸索才能不至於撞到巖壁，你聽到東
邊傳來陣陣滴水的聲音，可是伸手一摸卻仍是冷冰冰、又乾又硬的岩石
，地上佈滿了許多又黏又稠的不知名東西，使你每一步都走得異常艱辛
。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"cavern2",
	]));
	set("objects", ([
		__DIR__"npc/big_worm": 2,
		__DIR__"npc/huge_worm": 2,
	]) );

	setup();
	replace_program(ROOM);
}
