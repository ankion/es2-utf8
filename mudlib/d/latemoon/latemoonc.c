inherit ROOM;

void create()
{
    set("short","大廳後院");
	set("long", @LONG
這是晚月莊後的小小庭院，面積似乎不大，但花木扶疏，舉目四望，
竟種滿了無數梅花，婉約娟秀，別有一番滋味。清風徐來，梅花特有的
清香瀰漫在風中.....
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"latemoon5",
    "west" :__DIR__"latemoon7",
    "east" :__DIR__"latemoon1",
    "south" :__DIR__"latemoon4"

]));

	setup();
	replace_program(ROOM);
}
