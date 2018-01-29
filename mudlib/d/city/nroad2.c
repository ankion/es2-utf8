// nroad2.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short", "北驛道");
  set("long", @LONG
這是一條青石鋪地的大驛道，地處京師的北郊。北方入京必經
此地。往南走就可以到京師了。東北是連綿的羣山。
LONG
  );

  set("exits", ([
    "south"          : __DIR__"nroad1",
    "north"          : "/d/village/road2" 
  ]) );

  set("objects", ([
    "/u/cp/chater2" : 1, 
  ]) );

  set("outdoors", "city");

  setup();
  replace_program(ROOM);
}

