// Room: /d/death/bridge1.c

inherit ROOM;

void create()
{
	set("short", "奈何橋");
	set("long", @LONG
這裏是一條漫長的石橋，往南石橋延伸進大霧之中，望不到盡頭，
往北引隱約約有一座城樓，不過你分不清是真實的影像還是幻覺，東西
兩面都是一望無際的大霧，一陣陣陰冷的微風從霧中吹過。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"bridge",
]));

	setup();
	replace_program(ROOM);
}
