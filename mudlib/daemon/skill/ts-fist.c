// ts-first.c
//天山折梅手

inherit SKILL;

mapping *action = ({
	([	"action":		"$N左掌輕動右手向上一探一招「梅影疏斜」抓向$n的$l，姿態美妙",
		"dodge":		-30,
		"parry":		-70,
		"force":		210,
		"damage_type":	"抓傷"
	]),
	([	"action":		"$N倏地一個轉身雙手一送「梅香襲人」直銎$n$l",
		"dodge":		-10,
		"parry":		-60,
		"force":		190,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N身子微斜隨即跨出一步右手一劃使出「踏雪尋梅」拍向$n的$l",
		"dodge":		-30,
		"parry":		-40,
		"force":		110,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N雙手一抖「老梅虯枝」從一個匪夷所思的角度對準$n的$l抓去",
		"dodge":		10,
		"parry":		-60,
		"force":		190,
		"damage_type":	"抓傷"
	]),
	([	"action":		"$N左手虛晃右掌飄飄一招「映雪紅梅」擊向$n$l",
		"dodge":		-20,
		"parry":		-50,
		"force":		250,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N使出「梅凋無聲」凌空躍起冷不防在落地前對準$n$l拍出一掌",
		"dodge":		-70,
		"parry":		-40,
		"force":		180,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N右手在$n$l劃過隨後一招「梅妻鶴子」左手又向同一方位抓到",
		"parry":		-90,
		"force":		150,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N右手連搖左手使出「暗香浮動」，波的一聲擊向$n的$l",
		"parry":		-90,
		"force":		360,
		"damage_type":	"瘀傷"
	]),

});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("練天山折梅手必須空手。\n");
	if( (int)me->query("max_force") < 80 )
		return notify_fail("你的內力太弱無法練天山折梅手。\n");
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
		return notify_fail("你的體力不夠了休息一下再練吧。\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("你的內力不夠了休息一下再練吧。\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("kee", (damage_bonus - 80) / 2 );
		switch(random(5)) {
			case 0: return "你聽到「喀啦」一聲輕響竟似是骨碎的聲音ⅵ\n";
			case 1: return "$N勁力一吐$n的$l發出「喀」地一聲爆響ⅵ\n";
			case 2: return "只聽見$n的$l「喀」地一聲 ...\n";
			case 3: return "$N的雙手如同一條活魚一樣，迅捷無倫地擊中$n的$l！\n";
			case 4: return "天山折梅手果然名不虛傳，$n的$l立刻被印上一記！\n";
		}
	}
}

