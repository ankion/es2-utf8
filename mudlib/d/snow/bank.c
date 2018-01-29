// bank.c

inherit BANK;

void create()
{
	set("short", "安記錢莊");
	set("long", @LONG
這是一間素來以公平信用著稱的錢莊，錢莊的老闆還是個曾經中過
舉人的讀書人，你可以看到錢莊裏裏外外都打掃得乾乾淨淨，一個胖胖
的中年人坐在櫃檯後面，櫃檯上放著一塊牌子(sign)，往東是通往雪亭
鎮大街的大門。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"mstreet1",
]));

	set("objects", ([
 		__DIR__"npc/annihir" : 1 ]) );

	set("item_desc", ([
		"sign": @TEXT
這裏是錢莊，目前我們提供的服務有：
兌換(convert)錢幣。

TEXT
	]) );
//    set("no_fight", 1);
//    set("no_magic", 1);
	setup();
}
