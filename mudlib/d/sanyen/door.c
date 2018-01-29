// Room: /d/sanyen/door.c

inherit ROOM;

void create()
{
	set("short", "山煙寺寺門");
	set("long", @LONG
出現在眼前的是一座宏偉壯麗的寺門, 上方覆著鑲金的瓦片, 瓦
片的下方掛著一方翡翠匾額, 上面寫著『山煙寺』三個燙金大字。正
中的大門正緊緊關閉著, 只有在迎接大人物時纔會開啓。現在只開著
兩旁的偏門。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/sanyen/road1",
  "south" : "/d/sanyen/front_yard",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
