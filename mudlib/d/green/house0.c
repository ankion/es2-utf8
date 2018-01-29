// Room: /d/green/house0.c

inherit ROOM;

void create()
{
	set("short", "民宅");
	set("long", @LONG
這是一間簡陋的民宅，陰暗窄小的屋內散著一地的柴火和各式工具。
屋角的石爐上閃著微弱的火光，一鍋不知是什麼的東西正冒出陣陣香味。
另一角放著一張簡陋的木牀和幾張椅子。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/green/path3",
]));
	set("objects", ([
	"/d/green/npc/woman1" : 1,
	"/d/green/npc/woman2" : 1,
		]) );

	setup();
	replace_program(ROOM);
}
