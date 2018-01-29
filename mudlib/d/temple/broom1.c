// Room: /d/temple/broom1.c

inherit ROOM;

void create()
{
    set("short", "經樓");
	set("long", @LONG
這裏是靈心觀中收藏書籍的地方, 四周的書架上堆了滿滿的書。
有些書已經舊的紙張都泛黃了, 摸一摸可能就會散掉甚至變成飛灰。
你再仔細的看了看, 發現這裏都只是些尋常的修道的書籍, 似乎沒有
什麼特別的。角落裏有一座小小的木梯通往二樓。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/temple/broom2",
  "out" : "/d/temple/road2",
]));

	setup();
	replace_program(ROOM);
}
