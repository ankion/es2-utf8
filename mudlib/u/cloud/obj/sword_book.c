// sword_book.c

inherit ITEM;

void create()
{
        set_name("殘破劍譜", ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                et("long",
                        
"這似乎是一本什麼劍譜的前幾頁，雖然並沒有關於招式的詳細解說，可是\n"
                        "前面有關劍法的總綱與精義倒是不少。\n");
                set("value", 260);
                set("material", "paper");
                set("skill", ([
                        "name":                 "sword",        
                        "exp_required": 1000,
                        "sen_cost":             30,       
                        "difficulty":   20,   
                        "max_skill":    40    
                ]) );
        }
}

 
