// Room: /u/k/karrimor/temple/entrance.c

inherit ROOM;

void create()
{
	set("short", "靈心觀前");
	set("long", @LONG
在你眼前是一座古色古香的山門, 上面以龍飛鳳舞的筆跡書寫著
「靈心觀」三字, 據說是當年太陽神君「杞庸」親筆所題。往北方看
過去是一個頗大的廣場。門前則是一條石英岩鋪設的階梯沿著山腰往
東而下。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" : __DIR__"square",
     "south" : __DIR__"ladder1",
]));

    set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
