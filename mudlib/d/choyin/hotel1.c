// Room: /d/choyin/hotel1.c

inherit ROOM;

void create()
{
	set("short", "福林酒樓");
	set("long", @LONG
這裏便是喬陰縣馳名遠近的福林酒樓，連喬陰縣最熱鬧的一條大街
都以此命名，福林酒樓是一家近百年老店，傳到現在的這位掌櫃已經是
第三代，如果你是初到此地的外地人，不妨和他攀攀交情，酒樓一樓多
半是縣城裏熟客人，東北邊有一道方梯通往樓上雅座，往西則可以出大
街。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"hotel2",
		"west" : __DIR__"s_street2",
	]));
	set("objects", ([
		__DIR__"npc/boss" : 1,
		__DIR__"npc/sergeant" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
