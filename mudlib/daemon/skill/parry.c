// parry.c

inherit SKILL;

string *parry_msg = ({
	"只聽見「鏘」一聲，被$p格開了。\n",
	"結果「當」地一聲被$p擋開了。\n",
	"但是被$n用手中兵刃架開。\n",
	"但是$n身子一側，用手中兵刃格開。\n",
});

string *unarmed_parry_msg = ({
	"但是被$p格開了。\n",
	"結果被$p擋開了。\n",
});

string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
