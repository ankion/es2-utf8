// jiulou.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "太白酒樓");
        set("long", @LONG
你走到了一家大酒樓裏。四周的裝飾金壁輝煌，令人眼花繚亂，連餐
具的做工也極講究，不愧是京城的第一大酒樓。酒樓的菜餚是遠近聞名的
，在這經常可以看到一些達官貴族，據連當今皇上也曾微服來此以一飽口
福。
LONG
        );

        set("exits", ([
                "east":		__DIR__"street5",
		"up":		__DIR__"jiulou_2",
		]) );

        set("objects", ([
                __DIR__"npc/waiter" : 	1,
		__DIR__"npc/boss":	1,
		]) );
        setup();
}


