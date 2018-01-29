inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("宮保雞丁", ({ "chicken","food" }));
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "這是一道香辣可口的佳餚。\n");
          set("unit", "只");
          set("value", 50);
          set("food_remaining", 5);
          set("food_supply", 70);
     }
}


