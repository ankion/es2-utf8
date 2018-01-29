// Room: /d/sanyen/drag_field.c

inherit ROOM;

void create()
{
	set("short", "藥圃");
	set("long", @LONG
一片廣闊的藥圃, 藥香就是從這裏散發出來的。這裏似乎經過詳
細的規劃, 一塊一塊的, 哪邊種當歸, 哪邊種枸杞, 絕不會混在一起
。只是看來看去都只是些尋常的藥材, 看不到比較珍貴特殊的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"road2",
]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
