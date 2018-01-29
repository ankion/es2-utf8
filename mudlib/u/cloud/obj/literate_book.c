// sword_book.c

inherit ITEM;

void create()
{
        set_name("說文解字", ({ "literate book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"這是一本介紹讀書識字的入門書籍。\n"
                        "開篇上赫然寫着人之初，性本善什麼的。\n");
                set("value", 2000);
                set("material", "paper");
                set("skill", ([
                        "name":                 "literate",        
                        "exp_required": 0,
                        "sen_cost":             30,       
                        "difficulty":   20,   
                        "max_skill":    30    
                ]) );
        }
}

 
