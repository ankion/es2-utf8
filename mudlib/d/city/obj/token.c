inherit ITEM;

void create()
{
        set_name("出城令牌", ({ "token" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "一支遺失多年的令牌，或許在出城時還有用。\n");
                set("value", 0);
                set("material", "copper");
        }
}

