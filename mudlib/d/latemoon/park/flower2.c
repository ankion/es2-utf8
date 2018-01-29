inherit ROOM;

void create()
{
    set("short", "月洞門");
	set("long", @LONG
走進月洞門，只見迎面一帶翠嶂，擋在南面。只見白石嶺□，  
或如鬼怪，或如猛獸，縱橫拱立，上邊苔蘚成斑，藤蘿掩映，其
中微露羊腸小徑。往南進入翠嶂，往北是小花廳。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
      "north" :__DIR__"yard1",
      "south" :__DIR__"moonc",

]));

	setup();
	replace_program(ROOM);
}
