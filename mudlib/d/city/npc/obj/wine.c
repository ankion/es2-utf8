inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("狀元紅", ({"wine"}));
        set_weight(20000);
        if( clonep() )
            set_default_object(__FILE__);
          else {
        	set("long", "這是一罈香味濃郁的陳年老酒，是專待狀元高中時喝的酒。\n");
                set("unit", "壇");
                set("value", 350);
                set("max_liquid", 30);
        }
        set("liquid", ([
                "name" : "紅酒",
                "remaining" : 30,
                "drunk_bonus" : 7,
                "type" : "alcohol"
        ]) );
        setup();
}

