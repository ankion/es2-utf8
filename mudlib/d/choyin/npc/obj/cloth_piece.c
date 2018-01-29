// cloth_piece.c

inherit ITEM;

void create()
{
	set_name("從壽衣撕下的布條", ({ "shroud piece", "piece", "shroud" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "條");
		set("long",
			"這條布條是從一件壽衣上撕下來的，上面密密麻麻寫了許\多字。\n");
		set("material", "cloth");
		set("skill", ([
			"name": 		"spells",		// name of the skill
			"exp_required":	0,				// minimum combat experience required
											// to learn this skill.
			"sen_cost":		60,				// gin cost every time study this
			"difficulty":	25,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	40				// the maximum level you can learn
											// from this object.
		]) );
	}
}
