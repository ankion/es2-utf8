
inherit ROOM;

void create()
{
     set("short", "客房");
	set("long", @LONG
這是一間客房，兩邊擺了一對小茶几。上面的彩繪瓶中插了一束
瓊花，茶几旁兩張雕漆椅。整個房間簡樸幽靜，爲晚月莊供外客留宿
的一間廂房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" :__DIR__"two1",

]));

    set("objects", ([
        __DIR__"npc/guest" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
