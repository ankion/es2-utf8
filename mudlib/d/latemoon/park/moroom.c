inherit ROOM;

void create()
{
   set("short", "紫翎小軒");
	set("long", @LONG
你一進了小軒內，只覺異香撲鼻，那些奇草仙藤，越冷越蒼翠，
都結了實，似珊瑚豆子一般，累垂可愛。房內雪洞一般，清涼舒適  
，案上一個土定瓶，中供著數枝菊花，旁邊放了兩本書、茶甌茶杯  
而已，牀上只吊著青紗帳幔被褥，也十分樸實。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "east" :__DIR__"moon3",

]));

    set("objects", ([
        __DIR__"npc/girl_yu" : 1,
        __DIR__"npc/dodo1" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
