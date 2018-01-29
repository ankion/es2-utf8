inherit ROOM;

void create()
{
   set("short", "晚月莊後門");
	set("long", @LONG
這是晚月莊的後門，在美麗的湘園南側，這有一個木製的小門。
走出門外應是通往天山的小徑。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"paroad1",
    "south" :"/d/latemoon/sroad1",
]));

	setup();
	replace_program(ROOM);
}
