inherit ROOM;

void create()
{
    set("short", "沁芳橋");
	set("long", @LONG
你走至大橋前，見水如晶簾一般奔入，扶著藤欄過去，只見水
上落花愈多，其水愈清，溶溶蕩蕩，曲折縈紆，池邊兩行垂柳，雜
著桃、杏，遮天蔽日般，真無一些塵土。度過橋去則通往湖心亭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "north" :__DIR__"moonc",
       "south" :__DIR__"pavilion1",

]));

	setup();
	replace_program(ROOM);
}
