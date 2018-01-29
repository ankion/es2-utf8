// Room: /d/waterfog/sroad2.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
這是一條寬敞堅實的青石板大道，從這裏沿著山勢彎向西邊與南邊
，往西不遠處就是通往水煙閣的石階。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/waterfog/sroad1",
  "west" : "/d/waterfog/sroad3",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
