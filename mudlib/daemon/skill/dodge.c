// dodge.c

inherit SKILL;

string *dodge_msg = ({
	"但是和$p$l偏了幾寸。\n",
	"但是被$p機靈地躲開了。\n",
	"但是$n身子一側，閃了開去。\n",
	"但是被$p及時避開。\n",
	"但是$n已有準備，不慌不忙的躲開。\n",
});

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
