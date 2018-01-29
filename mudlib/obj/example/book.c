// An example book

inherit ITEM;

void create()
{
        set_name("柳家拳法要旨", ({ "book" }));
        set_weight(600);
        set("unit", "本");
        set("long",
                
"這是一本介紹柳家拳法的入門書，柳家拳法是雪亭鎮柳老拳師祖傳的拳法\n"
                
"，易學易懂，這本書雖然只介紹了柳家拳初入門的功夫，但是用來防身已\n"
                "經算不錯了，適合初學者。\n");
        set("value", 100);
        set("skill", ([
                "name":                 "liuh-ken",             // name of 
the skill
                "exp_required": 0,                              // minimum 
combat experience required
                                                                               
// to learn this skill.
                "sen_cost":             40,                             // 
gin cost every time study this
                "difficulty":   20,                             // the base 
int to learn this skill
                                                                               
// modify is gin_cost's (difficulty - int)*5%
                "max_skill":    10                              // the 
maximum level you can learn
                                                                               
// from this object.
        ]) );
}
 
