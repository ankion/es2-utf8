// Room: /d/snow/mstreet4.c

inherit ROOM;

void create()
{
	set("short", "雪亭鎮街道");
	set("long", @LONG
這裏是雪亭鎮的大街，一條小巷子通往東邊，西邊則是一間驛站，
由於雪亭鎮來往的商旅、官員並不很多，因此雖然是官府的驛站，也接
受百姓的信件，大街往北是一處山坳，從這裏遠遠地可以望見北方的野
羊山，出了山坳就是一條碎石路通往山上。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/snow/crossroad",
  "south" : "/d/snow/mstreet3",
  "west" : "/d/snow/postoffice",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
