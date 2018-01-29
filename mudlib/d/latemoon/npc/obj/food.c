inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("脆皮烤鴨", ({ "duck","food" }));
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "這是一隻看了都會流口水的、香噴噴的烤鴨。\n");
          set("unit", "只");
          set("value", 50);
          set("food_remaining", 5);
          set("food_supply", 80);
     }
}


