// phantomforce.c

inherit ITEM;

void create()
{
	set_name("域摩經", ({ "book" }));
	set_weight(600);
	set("unit", "本");
	set("long",
		"這是魔道修煉者夢寐以求的內功\祕訣「地靈心法」，書中記載了逆天而\n"
		"生、反轉五行生剋與內臟的心法。\n");
	set("value", 100);
	set("skill", ([
		"name": 		"phantomforce",	// name of the skill
		"exp_required":	1000000,		// minimum combat experience required
										// to learn this skill.
		"gin_cost":		30,				// gin cost every time study this
		"difficulty":	30,				// the base int to learn this skill
										// modify is gin_cost's (difficulty - int)*5%
		"max_skill":	40				// the maximum level you can learn
										// from this object.
	]) );
}
