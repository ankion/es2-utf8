// Room: /d/snow/jiulou_2f.c

inherit ROOM;

void create()
{
        set("short", "太白酒樓二樓");
        set("long", @LONG
你走上了太白酒樓的二樓，酒樓的雅座便設於此。大凡有來頭
的客人都到此飲酒作樂。在此經常可以遇上一些達官貴族，一些爲
做官的富家子弟就來此打進階的消息。牆邊有一道樓梯通往一樓的
茶座。
LONG
        );
        set("exits", ([ 
		"down":		__DIR__"jiulou",
        ]));

/*        set("objects", ([
                __DIR__"npc/waiter":       1,
                ]));
*/
        setup();
}

