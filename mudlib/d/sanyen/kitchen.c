// Room: /d/sanyen/kitchen.c

inherit ROOM;

void create()
{
	set("short", "香積廚");
        set("long", @LONG
一間整理相乾淨的廚房, 西北邊的角落裏砌了兩個大竈, 竈里正
燃著熊熊大火, 竈上分別放著一個大鍋(pot) 及一個蒸籠(steampot)
。鍋子及蒸籠正冒著陣陣的熱氣以及香氣, 你忍不住想打開來看看。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"corridor1",
]));

        set("item_desc", ([
            "pot": "一個冒著騰騰的熱氣的黑色大鐵鍋, 裏頭正煮著小米粥。\n",
            "steampot": "一個竹藤編成的蒸籠, 陣陣的香味使你想打開(open)來瞧一瞧。\n"
]) );

        set("objects", ([
            __DIR__"npc/cook_bonze" : 1 ]) );
	set("no_clean_up", 0);

	setup();
}

void init()
{
   add_action("do_open", ({"open"}) );
   add_action("do_take", ({"take"}) );
}

int do_open(string arg)
{
   if (!arg||arg!="steampot")
      return notify_fail("你要打開什麼？\n");
   if (!present("cook bonze"))
      {
       message_vision("$N打開蒸籠的蓋\子, 一股熱氣冒向$N的臉上。\n"
                      "$N仔細一看, 只見蒸籠裏排著一粒粒又白又Ｑ的大饅頭(maintal)。\n",this_player());
       return 1;
      }
   else
      {
       message_vision("燒飯僧說:阿彌陀佛 !! 施主請勿動手動腳, 妨礙貧僧煮飯。\n",
this_player());
       return 1;
      }
}

int do_take(string str)
{
   object ob;
   if (!str||str!="maintal")
       return notify_fail("你要拿什麼？\n");
   if (!present("cook bonze"))
      {
       if ((int)query("maintal_trigger")>=5)
          {
           return notify_fail("突然房間裏好像傳來夢憶柔的聲音說拿太多小心吃到噎著哦!!\n");
          }
       else
          {
           message_vision("$N從蒸籠裏拿出一粒熱乎乎的饅頭。\n",this_player());
           ob=new(__DIR__"npc/obj/maintal");
           ob->move(this_player());
           add("maintal_trigger",1);
           return 1;
          }
      }
   else
      {
       message_vision("燒飯僧說:阿彌陀佛 !! 施主偷東西是不好的行爲哦!!!\n",this_player());
       return 1;
      }
}

void reset()
{
        ::reset();
        delete("maintal_trigger");
}
