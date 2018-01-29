inherit ROOM;

void create()
{
   set("short", "長廊曲洞");
	set("long", @LONG
你走入一長廊曲洞，裏頭略略的有幾點山石，種著芭蕉，你可以
聽到潺潺的流水聲，這裏是園內假山開鑿的通道，蜿蜒盤□，從洞口
向外望去，是一碧清的水池。順著曲徑走去，轉了兩個彎子，看見一
座石板橋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "west" :__DIR__"moonc",
       "southeast" :__DIR__"bridge3",

]));

	setup();
	replace_program(ROOM);
}
