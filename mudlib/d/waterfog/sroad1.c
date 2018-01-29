// Room: /d/waterfog/sroad1.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
這是一條寬敞堅實的青石板大道，從這裏已經可以望見北邊山腰上
水煙閣琉璃色的屋瓦，映著山上茂密的楓樹林，顯得十分詩情畫意，由
於這條路是禁兵統領親自督造，因此造得格外平整，從這裏開始已經進
入由歷代水煙閣主人所管轄的封地，即使是官府也不能過問這片土地上
發生的事，因此你最好小心一點。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/snow/sroad5",
  "northwest" : "/d/waterfog/sroad2",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
