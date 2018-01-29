// tailory.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
  set("short", "布莊");
	set("long", @LONG
你現在正站在布莊裏。靠近門口的牆壁上掛着招牌(sign)。
LONG
);
  set("exits", ([
    "north": "/u/cloud/nwroad2" ]) );

  set("objects", ([
    "/u/cloud/npc/tailor" : 1,
  ]) );

  set("item_desc", ([
     "sign": (: look_sign :),
  ]) );

  setup();

}

string look_sign(object me)
{
  return "招牌寫著：衣。\n";
}

