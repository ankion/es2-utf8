// Room: /d/canyon/fantasy1.c

inherit ROOM;

void create()
{
	set("short", "夢幻迷境通道");
	set("long", @LONG
來到鏡內，前面呈現三面通道，各個通道皆有其不同的氣氛傳出
，中道有濃厚的竹之氣息，上道迷香之味不止，下道嘔味不停，不定
的上空，不停蠢地之幻地，空氣被抽絲剝繭，呼吸也愈來愈困難，不
停變動的景象，快決定吧!!暗中之招喚，心中爲之一震，快步踏離此
一不祥的空間。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"up" : __DIR__"dream/tmp",
		"down" : __DIR__"evil/tmp",
		"back" : __DIR__"stone_forest3",
		"center" : __DIR__"bamboo/bamboo1",
]));

	setup();
	replace_program(ROOM);
}
