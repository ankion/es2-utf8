// book1.c

inherit ITEM;

void create()
{
         string *names = ({
                "「笑傲江湖」", "「天龍八部」", 
                "「七劍下天山」", "「遊俠郭解傳」",
                "「七種武器」", "「楚留香傳奇之血海飄香」",
                "「四大名捕」", "「洪武劍俠圖」" });     
        set_name( names[random(sizeof(names))], ({ "book" }));
        set_weight(600);
        set("unit", "本");
        set("long", "這是隱士們常看的書籍。\n");
        set("value", 100);
        set("skill", ([
                "name":                 "unarmed",
                "exp_required": 100, 
                "sen_cost":             20, 
                "difficulty":   30,
                "max_skill":    80,  
        ]) );
}    
