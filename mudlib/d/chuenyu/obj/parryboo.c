// An example book

inherit ITEM;

void create()
{
        set_name("過招要旨" , ({ "parrybook" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "這是一本介紹拆招卸力之法的入門書\n");
        set("value", 100);
        set("skill", ([
                "name":                 "parry",      
                "exp_required": 2000,       
                "sen_cost":             20,
                "difficulty":   15,  
                "max_skill":    60     
        ]) );
}
