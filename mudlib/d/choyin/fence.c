// Room: /d/choyin/fence.c
# include <room.h>
inherit ROOM;

void create()
{
  set("short", "竹林");
  set("long", @LONG
諾大的一片竹林，密密匝匝，望不道盡頭。遊目四顧，沒有路了。
微風乍起，竹林深處現出一角竹籬(fence)。
LONG
);
  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"club", 
    "eastup" : __DIR__"rockyu",
  ]));
  set("item_desc", ([
    "fence":"籬笆依地勢而曲折延伸，你注意到柴門裏面有一間草堂。\n",
  ]) );
  create_door("west", "柴門", "east", DOOR_CLOSED);
  set("no_clean_up", 0);      
  setup();
  replace_program(ROOM);
}
