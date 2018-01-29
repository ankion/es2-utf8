// book.c

inherit ITEM;

void create()
{
	string *names = ({
		"「嘉德文選」", "「九韜」", "「太公辯」", "「樑父文集」",
		"「說律」", "「古文志」", "「鄉書」", "「佾風齋詩集」",
		"「寒士列傳」", "「水龍圖注」"
	});

	set_name( names[random(sizeof(names))], ({ "book" }));
	set_weight(600);
	set("unit", "本");
	set("long", "這是時下讀書人常看的書籍。\n");
	set("value", 100);
	set("skill", ([
		"name": 		"literate",		// name of the skill
		"exp_required":	0,				// minimum combat experience required
										// to learn this skill.
		"sen_cost":		40,				// gin cost every time study this
		"difficulty":	30,				// the base int to learn this skill
										// modify is gin_cost's (difficulty - int)*5%
		"max_skill":	50				// the maximum level you can learn
										// from this object.
	]) );
}
