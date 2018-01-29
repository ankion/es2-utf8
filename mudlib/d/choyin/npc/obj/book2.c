// book2.c

inherit ITEM;

void create()
{
        string *names = ({
                "「祕傳八步趕蟬」", "「陸地飛行之法」", "「寒梅弄影之法」", "「穿花繞樹要訣」",
                "「八卦步法」",   });

        set_name( names[random(sizeof(names))], ({ "book" }));
        set_weight(600);
        set("unit", "本");
        set("long", "這是隱士們常看的書籍。\n");
        set("value", 100);
        set("skill", ([
                "name":                 "dodge",
                "exp_required": 100, 
                "sen_cost":     20, 
                "difficulty":   30,
                "max_skill":    80,  
        ]) );
} 
