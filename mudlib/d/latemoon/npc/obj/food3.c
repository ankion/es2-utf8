inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("水餃", ({ "boiled dumplings","food" }));
    set_weight(100);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "這是一個手工細膩的水餃，看起來很好吃。\n");
          set("unit", "個");
          set("value", 50);
          set("food_remaining", 2);
          set("food_supply", 30);
     }
}


