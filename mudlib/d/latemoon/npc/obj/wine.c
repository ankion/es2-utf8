inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("女兒紅", ({"wine"}));
        set_weight(20000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
   "這是一罈香味濃郁的陳年老酒，是存給待嫁女兒喝的酒。\n"
   "你聞了聞，好香好香哦!你有點想喝它 (drink)\n");
                set("unit", "壇");
                set("value", 20);
                set("max_liquid", 30);
        }
        set("liquid", ([
        	"name" : "紅酒",
        	"remaining" : 30,
        	"drunk_bonus" : 5,
        	"type" : "alcohol"
        ]) );
        setup();
}

