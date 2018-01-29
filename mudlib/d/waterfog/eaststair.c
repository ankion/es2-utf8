// Room: /d/waterfog/eaststair.c

inherit ROOM;

void create()
{
	set("short", "東側廳");
	set("long", @LONG
這裏是水煙閣東邊的側廳，東邊隔著欄杆就是深不見底的深谷，從
這裏向外眺望，更可以感受到水煙閣孤立於獨峯之上，傲視羣山的氣魄
，這裏有一道階梯通往二樓，往北是廚房與儲存雜物的倉庫。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"up" : __DIR__"east_2f",
		"south" : __DIR__"easthall",
		"north" : __DIR__"kitchen",
]));

	setup();
	replace_program(ROOM);
}
