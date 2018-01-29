
inherit ROOM;

void create()
{
    set("short", "上等廂房");
	set("long", @LONG
這是一間上等廂房，光線適中。近窗邊有一張桌子，旁有書櫥!
還有一個古琴放在平臺上! 牆上除了美麗的飾物外，還掛了一些書畫
有一濃郁清新的書香氣息! 通常是給遠道而來的貴客休憩夜宿的一間
上等廂房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
      "north" :__DIR__"two2",

]));

    set("objects", ([
        __DIR__"npc/tguest" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
