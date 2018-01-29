//hurt_drug.c

inherit ITEM;

void create()
{
        set_name("金瘡藥",({"medicine"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "一顆金瘡藥, 可以用來敷上(apply)治傷 。\n");
            set("unit","顆");
            set("value", 2000);
        }
}

void init()
{
        add_action("apply_medicine","apply");
}

int apply_medicine()
{
        int value = 20;
        int diff;

        if(this_player()->is_fighting())
            return notify_fail("戰鬥中不能用藥治傷!\n");
        diff = this_player()->query("max_kee")-this_player()->query("eff_kee");
        if(!(diff))    return notify_fail("你沒有受傷啊?\n");
        if(value > diff) value = diff;

        message_vision("$N敷上金瘡藥 .\n",this_player());
        this_player()->add("eff_kee",value);
        destruct(this_object());
        return 1;
}


