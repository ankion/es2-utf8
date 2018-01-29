inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("雪花糕", ({ "cake" }));
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "這是一塊精緻可口的小點心，似雪花般柔軟。\n");
          set("unit", "塊");
          set("value", 50);
          set("food_remaining", 5);
          set("food_supply", 80);
     }
}


