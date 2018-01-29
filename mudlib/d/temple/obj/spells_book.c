// spells_book.cok.c

inherit ITEM;

void create()
{
        set_name("符咒簡介", ({ "spellsbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",

"這似乎是一本符咒的簡介，裏面畫着一些稀奇古怪的符號\n"
                );
                set("value", 260);
                set("material", "paper");
                set("skill", ([
                        "name":     "spells",    // name of the skill
                    "exp_required": 100, // minimum combat experience equired
                        "sen_cost":  30, // gin cost every time study this
                      "difficulty":  10,//the base int to learn this skill
        // modify is gin_cost's (difficulty - int)*5%�)
                    "max_skill":  20 // the maximum level you can learn

        // from this object.
                ]) );
        }
}
