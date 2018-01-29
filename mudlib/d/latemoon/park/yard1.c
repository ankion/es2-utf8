
inherit ROOM;

void create()
{
    set("short","前院");
	set("long", @LONG
你走到前院，你看到幾塊山石，東面一處假山小池。其上植有藤  
蘿、青芷，異草芬芳荔薛。池中幾尾小魚自在的游來游去。假山外隔
著圍籬，有一種山懷中的小花園的感覺。.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" : "/d/latemoon/front_yard",
     "south" :__DIR__"flower2",

]));
    set("outdoors", "latemoon");

	setup();
	replace_program(ROOM);
}
