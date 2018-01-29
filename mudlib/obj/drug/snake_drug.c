//snake_drug.c

inherit COMBINED_ITEM;

void create()
{
  set_name("蛇藥",({"drug","snake drug"}));
  set("long",
      "這是一包用來解蛇毒的藥\n"
      "可以用(apply)來解蛇毒!\n");
  set("value",1000);
  set("unit","包");
  set("base_unit","份");
  set("base_weiht",100);
  set_amount(1);
}

void init()
{
  add_action("do_apply","apply");
}

int do_apply()
{
        object me;
        me=this_player();
  if(((int) (me->query_condition("snake_poison"))) <= 0)
        return notify_fail("你沒有中蛇毒。\n");
  message_vision("$N服下蛇藥，頓時感覺好多了。",me);
        me->apply_condition("snake_poison",
                (int)me->query_condition("snake_poison") - 1);
  if((int) (me->query_condition("snake_poison")))
        message_vision("但是$N中的蛇毒並沒有完全清除。\n",me);
        else
        message_vision("$N終於清除了體內所有的蛇毒！\n",me);
  add_amount(-1);

  return 1;
}


