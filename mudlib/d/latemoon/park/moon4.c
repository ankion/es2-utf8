inherit ROOM;

void create()
{
   set("short", "暖香榭");
	set("long", @LONG
暖香榭位於水池東岸，秋水山房之西，依巖爲屋，結構曲折，
極幽致，室小而精，尚樸去華，淵然靜修，古香襲人。走進這裏
你有一種心源湛澈，天地虛靈，彷佛置身於仙境的感覺。往西面
望去，水底亭臺，歷歷可鑑。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "southwest" :__DIR__"paroad1",
       "north" :__DIR__"bridge3",

]));

    set("objects", ([
        __DIR__"npc/bird" : 2,
        __DIR__"npc/maysan" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
