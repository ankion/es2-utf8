// duchang2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "賭場");
	set("long", @LONG
這裏是賭場的二樓，很多人在圍着幾張桌子高聲叫嚷，煞是熱鬧。
靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG
        );
      set("exits", ([
        "down" : __DIR__"duchang",
      ]) );

        set("item_desc", ([
            "sign": "招牌寫著：賭(bet)：押注一兩紋銀，贏了得二兩。\n",
        ]) );

        setup();

}

void init()
{
  add_action("do_bet", "bet");
}

int do_bet(string arg)
{
  // TODO: 
  if(random(10) < 8) {
  }

  return 1;
}
