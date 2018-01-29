inherit COMBINED_ITEM;

void create()
{
        set_name("女兒紅", ({"wine"}));
        set("long",
   "這是一罈香味濃郁的陳年老酒，是存給待嫁女兒喝的酒。\n"
   "你聞了聞，好香好香哦!你有點想喝它 (drink)\n");
        set("unit", "壇");
        set("base_unit", "壇");
        set("base_weight", 20000);
        set_amount(1);
}

void init()
{
        if( this_player()==environment() )
            add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        if( !arg ) return notify_fail("你要喝甚麼呢? \n");
        message_vision(
           "$N提起一罈酒，呼嚕呼嚕的大口喝了下去。\n"
           "只見$N臉上泛起一陣紅暈，身子不覺晃了起來! \n",this_player()  );
        this_player()->receive_damage("gin",10);
        this_player()->receive_heal("sen",20);

        add_amount(-1);
        return 1;
}
