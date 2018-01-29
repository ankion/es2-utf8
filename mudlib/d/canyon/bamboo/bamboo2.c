// Room: /d/canyon/bamboo/bamboo2.c

inherit ROOM;

void create()
{
	set("short", "竹林道");
	set("long", @LONG
此處的竹林比起入口的竹子更爲高大聳直，也有些小動物在這四
周跳來跳去，跑來跑去的，更是生氣盎然，不時有也黃鶯唱吟著美妙
的詩句，清新宛然，人間仙境，只是偶爾有那怪異的強風襲捲而致，
另人難以忍受，在往入探頭，有一似人大的黃石挺立於內，而其四周
隱隱約約有些許正氣溢散而出。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"bamboo3",
		"south" : __DIR__"bamboo1",
]));

	setup();
	replace_program(ROOM);
}
