// Room: /d/oldpine/lake.c

inherit ROOM;

void create()
{
	set("short", "水潭");
	set("long", @LONG
你現在正站在一個深不見底的水潭邊上，從潭底不時有氣泡冒上來
，散發著一股詭異的香味，水潭邊長滿了黃色葉子的怪草，四周陡峭的
山壁近乎直立，擡頭只見一個半圓形的天空，唯一的出路大概只有往北
山泉流入水潭的缺口。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/oldpine/riverbank1",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/oldpine/npc/serpent" : 5,
]));
	set("resource/water", 1);
	setup();
	replace_program(ROOM);
}
