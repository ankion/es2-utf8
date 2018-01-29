// bank.c

inherit BANK;

void create()
{
	set("short", "旺金錢莊");
	set("long", @LONG
這是一間素來不講信用的錢莊，錢莊的老闆倒是讀過幾年書，腦筋
很活絡，你可以看到錢莊裏裏外外都打掃得乾乾淨淨，一個精瘦精瘦的
中年人坐在櫃檯後面，櫃檯上放著一塊牌子(sign)，往南是通往京城街
道的大門。
LONG
	);
	set("exits", ([ 
  "south" : "/d/city/street8",
]));

	set("objects", ([
 		"/d/city/npc/microsof" : 1 ]) );






	set("item_desc", ([
		"sign": @TEXT
我們提供的服務有：

convert     兌換錢幣，自點數目，出門後發現少錢概不負責。

TEXT
	]) );
    set("no_fight", 1);
    set("no_magic", 1);
	setup();
}
