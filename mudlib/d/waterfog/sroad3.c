// Room: /d/waterfog/sroad3.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
這是一條寬敞堅實的青石大道，大道沿著山腰往東向山下延伸，一
道長長的白石階梯從這裏往北邊上山，從這裏仰望階梯的盡頭有一座雄
偉的樓閣，那就是著名的「水煙閣」。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/d/waterfog/stair1",
  "east" : "/d/waterfog/sroad2",
//  "west" : "/d/temple/sroad"
]));
	set("objects", ([
		__DIR__"npc/guard": 2 ]) );

	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
