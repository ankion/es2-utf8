// sttormdance.c
#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
	"但$n一式「蕙芳下凡」隨著輕輕一嘆，順著$N的招式飄出六尺之外！\n",
	"$n雙腳微動翩然起舞，一招「雙成獻舞」，堪堪閃過$N的這招！\n",
	"$n使出「織女于歸」，突然幻化成一雙倩影，$N從其中一人透體而過！\n",
	"$n一式「天女散花」，自水袖中散出一片花雨，$N被花影迷濛了雙眼，與$n擦肩而過\n",
	"$n一招「嫦娥奔月」，輕輕一縱優雅的自$N頭頂越過！\n"
});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
	if( (string)me->query("gender") != "女性" )
		return notify_fail("七寶天嵐舞只有女性才能練。\n");
	if( (int)me->query("spi") < 20 )
		return notify_fail("你的靈性不夠，沒有辦法練七寶天嵐舞。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，不能練七寶天嵐舞。\n");
	me->receive_damage("sen", 30);
	return 1;
}

void skill_improved(object me)
{
        int s;

//        s = (int) me->query_skill("dodge",2)- me->query("dodge",1)/2;
          s = (int) me->query_skill("stormdance",1) ;

        if( s%10==9 && (int)me->query("per") < s/4) {
                tell_object(me, HIW "由於你勤練舞技，你的容貌提高了\n" NOR);
                me->add("per", 2);
        }
}


