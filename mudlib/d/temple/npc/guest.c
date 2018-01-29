inherit NPC;

void create()
{
     set_name("進香客", ({"guest"}) );
     set("gender", "男性");
     set("age", 31);
     set("long", 
         "一個福福泰泰的中年人, 他正氣喘噓噓地走著石梯道\n");
     set("combat_exp", 600);
     set("attitude", "friendly");
     setup();
     add_money("silver", 5);
}
