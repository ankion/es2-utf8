// Room: /d/green/shop0.c

inherit ROOM;

void create()
{
	set("short", "沈記商行");
	set("long", @LONG
這裏是青石村唯一的商店 -- 沈記商行, 在這裏村民可以購買
日常生活用品, 工具, 甚至於棺材. 真可以說是一間「雜」貨店.
屋內相當的擁擠, 到處都是箱子和雜物.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/green/path4",
]));
	set("objects", ([
	"/d/green/npc/shen" : 1,
	"/d/green/npc/woman1" : 1,
	]) );

	setup();
	replace_program(ROOM);
}
