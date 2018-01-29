// Room: /d/choyin/e_gate.c

inherit ROOM;

void create()
{
	set("short", "東城門");
	set("long", @LONG
    這裏喬陰縣城的東門，一座高大的石牌樓上面刻著「北門」兩個大
字，一條土路青鬱郁地通往南邊的山上，石牌樓旁蹲著一隻鐵獅. 與南
北兩城門相比, 北門這一帶顯得比較冷清，偶見幾個採藥, 砍柴之人由
此出入。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"e_street1",
  "east" : __DIR__"solidpath1",
]));
        set("objects",([
          __DIR__"npc/cityguard":2,
          __DIR__"npc/ghost":1,
                      ]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
