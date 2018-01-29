// spicyclaw.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N左掌微分，右手一長使出一招「毒龍撲舟」，抓向$n的$l",
		"dodge":		-30,
		"parry":		-70,
		"force":		160,
		"damage_type":	"抓傷"
	]),
	([	"action":		"$N倏地一個轉身，雙手一翻「攛鍋手」直摜$n$l",
		"dodge":		-10,
		"parry":		-60,
		"force":		140,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N身子微斜，隨即跨出一步，左手忽掌忽爪使出「撮灰手」，拍向$n的$l",
		"dodge":		-30,
		"parry":		-40,
		"force":		120,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N使出「青蛇十段錦」，雙手滑溜異常對準$n的$l抓去",
		"dodge":		10,
		"parry":		-60,
		"force":		140,
		"damage_type":	"抓傷"
	]),
	([	"action":		"$N左手虛晃，右掌飄飄，一招「樑上君子」擊向$n$l",
		"dodge":		-20,
		"parry":		-50,
		"force":		150,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N使出「撥草尋履」，凌空躍起，冷不防在落地前對準$n$l踢出一腳",
		"dodge":		-70,
		"parry":		-40,
		"force":		180,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N右手在$n$l劃過，隨後一招「隨棍上身」左爪又向同一方位抓到",
		"parry":		-90,
		"force":		100,
		"damage_type":	"抓傷"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("練油流麻香手必須空手。\n");
	if( (int)me->query("max_force") < 80 )
		return notify_fail("你的內力太弱，無法練油流麻香手。\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("你的體力不夠了，休息一下再練吧。\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("你的內力不夠了，休息一下再練吧。\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("kee", (damage_bonus - 100) / 2 );
		switch(random(3)) {
			case 0: return "你聽到「喀啦」一聲輕響，竟似是骨碎的聲音！\n";
			case 1: return "$N勁力一吐，$n的$l發出「喀」地一聲爆響！\n";
			case 2: return "只聽見$n的$l「喀」地一聲 ...\n";
		}
	}
}
