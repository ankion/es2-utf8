// duchang.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "賭場");
	set("long", @LONG
你現在正站在賭場裏。靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
          "north": __DIR__"eroad1", 
          "up": __DIR__"duchang2",
        ]) );

        set("item_desc", ([
          "sign": "招牌上寫着：賭，勝者贏雙。\n",
        ]) );

        set("objects", ([
          "/u/cloud/npc/judge" : 1,
        ]) );
 
        setup();

}
