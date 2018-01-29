// /d/city/shangshu/kefang

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "客房");
        set("long",@LONG
你走進了尚書府的客房。客房不大，但佈置得比較整潔。靠窗的
小桌上摞放着幾本書(book)，另一側的牆上則掛了把寶劍，似乎告訴
來人此地主人競是文武雙全。
LONG
        );

        set("exits", ([
		"west":		__DIR__"road2"
                ]));

	set("item_desc", ([
		"book":	(: "一本詩詞集，上面圈圈點點了一些句子.\n" :),
		]) );

	create_door ("west", "木門", "east", DOOR_CLOSED);

        setup();
}

