// jiyuan2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "香茗坊二樓");
	set("long", @LONG
這是茶樓的二層，附近的文人墨客常喜歡在此品茗作賦。
    裏首擺着個棋盤。
LONG
        );
        set("exits", ([
                "down"  : "/u/cloud/tearoom" ]) );

	set("objects", ([
                "/u/cloud/npc/chess_player" : 1,
	]) );

        setup();

}


