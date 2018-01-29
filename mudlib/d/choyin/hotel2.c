// Room: /d/choyin/hotel2.c

inherit ROOM;

void create()
{
	set("short", "福林酒樓");
	set("long", @LONG
這裏是福林酒樓的二樓雅座，這裏的客人大多衣冠鮮明，若不是富
豪巨紳，便是秀才舉人，使你不知不覺跟著斯文起來，從這裏可以眺望
喬陰縣城的市景，東邊不遠處隔著幾棟建築便是縣府衙門，南邊是碧波
盪漾的翠柳湖，湖對岸的雨橋莊在柳樹間若隱若現，東邊許多民房，再
過去便是一方方的稻田，北邊可望見樹王墳的石臺，以及喬陰縣城北的
建築。你可以沿角落的方梯回到一樓，或者到三樓的客房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"hotel3",
		"down" : __DIR__"hotel1",
	]));
	set("objects", ([
		__DIR__"npc/youngman": 1,
		__DIR__"npc/servant": 3
	]) );

	setup();
	replace_program(ROOM);
}
