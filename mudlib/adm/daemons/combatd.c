// combatd.c

#pragma optimize

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;

string *guard_msg = ({
        CYN "$N注視著$n的行動，企圖尋找機會出手。\n" NOR,
        CYN "$N正盯著$n的一舉一動，隨時準備發動攻勢。\n" NOR,
        CYN "$N緩緩地移動腳步，想要找出$n的破綻。\n" NOR,
        CYN "$N目不轉睛地盯著$n的動作，尋找進攻的最佳時機。\n" NOR,
        CYN "$N慢慢地移動著腳步，伺機出手。\n" NOR,
});

string *catch_hunt_msg = ({
        HIW "$N和$n仇人相見分外眼紅，立刻打了起來！\n" NOR,
        HIW "$N對著$n大喝：「可惡，又是你！」\n" NOR,
        HIW "$N和$n一碰面，二話不說就打了起來！\n" NOR,
        HIW "$N一眼瞥見$n，「哼」的一聲衝了過來！\n" NOR,
        HIW "$N一見到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
        HIW "$N喝道：「$n，我們的帳還沒算完，看招！」\n" NOR,
        HIW "$N喝道：「$n，看招！」\n" NOR,});

string *winner_msg = ({
        CYN "\n$N哈哈大笑，說道：承讓了！\n\n" NOR,
        CYN "\n$N雙手一拱，笑著說道：承讓！\n\n" NOR,
        CYN "\n$N勝了這招，向後躍開三尺，笑道：承讓！\n\n" NOR,
        CYN "\n$n臉色微變，說道：佩服，佩服！\n\n" NOR,
        CYN "\n$n向後退了幾步，說道：這場比試算我輸了，佩服，佩服！\n\n" NOR,
        CYN "\n$n向後一縱，躬身做揖說道：閣下武藝不凡，果然高明！\n\n" NOR,
});

void create()
{
        seteuid(getuid());
        set("name", "戰鬥精靈");
        set("id", "combatd");
}

string damage_msg(int damage, string type)
{
        string str;

//      return "造成 " + damage + " 點" + type + "。\n";

        if( damage == 0 ) return "結果沒有造成任何傷害。\n";

        switch( type ) {
        case "□傷":
        case "割傷":
                if( damage < 10 ) return "結果只是輕輕地劃破$p的皮肉。\n";
                else if( damage < 20 ) return 
"結果在$p$l劃出一道細長的血痕。\n";
                else if( damage < 40 ) return 
"結果「嗤」地一聲劃出一道傷口！\n";
                else if( damage < 80 ) return 
"結果「嗤」地一聲劃出一道血淋淋的傷口！\n";
                else if( damage < 160 ) return 
"結果「嗤」地一聲劃出一道又長又深的傷口，濺得$N滿臉鮮血！\n";
                else return 
"結果只聽見$n一聲慘嚎，$w已在$p$l劃出一道深及見骨的可怕傷口！！\n";
                break;
        case "刺傷":
                if( damage < 10 ) return "結果只是輕輕地刺破$p的皮肉。\n";
                else if( damage < 20 ) return "結果在$p$l刺出一個創口。\n";
                else if( damage < 40 ) return 
"結果「噗」地一聲刺入了$n$l寸許！\n";
                else if( damage < 80 ) return 
"結果「噗」地一聲刺進$n的$l，使$p不由自主地退了幾步！\n";
                else if( damage < 160 ) return 
"結果「噗嗤」地一聲，$w已在$p$l刺出一個血肉□糊的血窟窿！\n";
                else return 
"結果只聽見$n一聲慘嚎，$w已在$p的$l對穿而出，鮮血濺得滿地！！\n";
                break;
        case "瘀傷":
                if( damage < 10 ) return 
"結果只是輕輕地碰到，比拍蒼蠅稍微重了點。\n";
                else if( damage < 20 ) return "結果在$p的$l造成一處瘀青。\n";
                else if( damage < 40 ) return 
"結果一擊命中，$n的$l登時腫了一塊老高！\n";
                else if( damage < 80 ) return 
"結果一擊命中，$n悶哼了一聲顯然吃了不小的虧！\n";
                else if( damage < 120 ) return 
"結果「砰」地一聲，$n退了兩步！\n";
                else if( damage < 160 ) return 
"結果這一下「砰」地一聲打得$n連退了好幾步，差一點摔倒！\n";
                else if( damage < 240 ) return 
"結果重重地擊中，$n「哇」地一聲吐出一口鮮血！\n";
                else return 
"結果只聽見「砰」地一聲巨響，$n像一捆稻草般飛了出去！！\n";
                break;
        default:
                if( !type ) type = "傷害";
                if( damage < 10 ) str =  "結果只是勉強造成一處輕微";
                else if( damage < 20 ) str = "結果造成輕微的";
                else if( damage < 30 ) str = "結果造成一處";
                else if( damage < 50 ) str = "結果造成一處嚴重";
                else if( damage < 80 ) str = "結果造成頗爲嚴重的";
                else if( damage < 120 ) str = "結果造成相當嚴重的";
                else if( damage < 170 ) str = "結果造成十分嚴重的";
                else if( damage < 230 ) str = "結果造成極其嚴重的";
                else str =  "結果造成非常可怕的嚴重";
                return str + type + "！\n";
        }
}

string eff_status_msg(int ratio)
{
        if( ratio==100 ) return HIG "看起來氣血充盈，並沒有受傷。" NOR;
        if( ratio > 95 ) return HIG 
"似乎受了點輕傷，不過光從外表看不大出來。" NOR;
        if( ratio > 90 ) return HIY "看起來可能受了點輕傷。" NOR;
        if( ratio > 80 ) return HIY "受了幾處傷，不過似乎並不礙事。" NOR;
        if( ratio > 60 ) return HIY "受傷不輕，看起來狀況並不太好。" NOR;
        if( ratio > 40 ) return HIR 
"氣息粗重，動作開始散亂，看來所受的傷著實不輕。" NOR;
        if( ratio > 30 ) return HIR "已經傷痕累累，正在勉力支撐著不倒下去。" 
NOR;
        if( ratio > 20 ) return HIR "受了相當重的傷，只怕會有生命危險。" NOR;
        if( ratio > 10 ) return RED 
"傷重之下已經難以支撐，眼看就要倒在地上。" NOR;
        if( ratio > 5  ) return RED "受傷過重，已經奄奄一息，命在旦夕了。" 
NOR;
        return RED "受傷過重，已經有如風中殘燭，隨時都可能斷氣。" NOR;
}

string status_msg(int ratio)
{
        if( ratio==100 ) return HIG "看起來充滿活力，一點也不累。" NOR;
        if( ratio > 95 ) return HIG "似乎有些疲憊，但是仍然十分有活力。" NOR;
        if( ratio > 90 ) return HIY "看起來可能有些累了。" NOR;
        if( ratio > 80 ) return HIY 
"動作似乎開始有點不太靈光，但是仍然有條不紊。" NOR;
        if( ratio > 60 ) return HIY "氣喘噓噓，看起來狀況並不太好。" NOR;
        if( ratio > 40 ) return HIR "似乎十分疲憊，看來需要好好休息了。" NOR;
        if( ratio > 30 ) return HIR 
"已經一副頭重腳輕的模樣，正在勉力支撐著不倒下去。" NOR;
        if( ratio > 20 ) return HIR "看起來已經力不從心了。" NOR;
        if( ratio > 10 ) return RED 
"搖頭晃腦、歪歪斜斜地站都站不穩，眼看就要倒在地上。" NOR;
        return RED "已經陷入半昏迷狀態，隨時都可能摔倒暈去。" NOR;
}

varargs void report_status(object ob, int effective)
{
        if( effective ) 
                message_vision( "( $N" + eff_status_msg(
                        (int)ob->query("eff_kee") * 100 / 
(int)ob->query("max_kee") ) 
                        + " )\n", ob);
        else
                message_vision( "( $N" + status_msg(
                        (int)ob->query("kee") * 100 / 
(int)ob->query("max_kee") ) 
                        + " )\n", ob);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
        int status, level, power;

        if( !living(ob) ) return 0;

        level = ob->query_skill(skill);

        switch(usage) {
                case SKILL_USAGE_ATTACK:
                        level += ob->query_temp("apply/attack");
                        break;
                case SKILL_USAGE_DEFENSE:
                        level += ob->query_temp("apply/defense");
                        break;
        }

        if( !level ) return (int)ob->query("combat_exp") / 2;

        if( (status = ob->query("max_sen")) > 0 )
                power = (level*level*level) / 3 /status * (int)ob->query("sen") ; 
        else
                power = (level*level*level) / 3;

        return power + ob->query("combat_exp");
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int 
attack_type)
{
        mapping my, your, action;
        string limb, *limbs, result;
        string attack_skill, force_skill, martial_skill, dodge_skill, 
parry_skill;
        mixed foo;
        int ap, dp, pp;
        int damage, damage_bonus, defense_factor;
        int wounded = 0;
        //int cost;

        my = me->query_entire_dbase();
        your = victim->query_entire_dbase();

        //
        // (1) Find out what action the offenser will take.
        //
        action = me->query("actions");
        if( !mapp(action) ) {
                me->reset_action();
                action = me->query("action");
                if( !mapp(action) ) {
                        CHANNEL_D->do_channel( this_object(), "sys",
                                sprintf("%s(%s): bad action = %O",
                                        me->name(1), me->query("id"), 
me->query("actions", 1)));
                        return 0;
                }
        }
        result = "\n" + action["action"] + "！\n";

        //
        // (2) Prepare AP, DP for checking if hit.
        //
        if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
        else                                    attack_skill = "unarmed";

        limbs = victim->query("limbs");
        limb = limbs[random(sizeof(limbs))];

        ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
        if( ap < 1) ap = 1;

        dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( dp < 1 ) dp = 1;
        if( victim->is_busy() ) dp /= 3;

        //
        // (3) Fight!
        //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
        //     AP and DP are greater than zero, so we always have chance to hit
        //     or be hit.
        //
        if( random(ap + dp) < dp ) {       // Does the victim dodge this hit?

                dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

                if( dp < ap && (!userp(victim) || !userp(me)) 
                &&      random(your["gin"]*100/your["max_gin"] + your["int"]) 
> 50 ) {
                        your["combat_exp"] += 1;
                        victim->improve_skill("dodge", 1);
                }

    // This is for NPC only. NPC have chance to get exp when fail to hit.
                     if( (ap < dp) && !userp(me) ) {
                        if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
                        me->improve_skill(attack_skill, random(my["int"]));
                }
                damage = RESULT_DODGE;

        } else {

                //
                //      (4) Check if the victim can parry this attack.
                //
                if( victim->query_temp("weapon") ) {
                        pp = skill_power(victim, "parry", 
SKILL_USAGE_DEFENSE);
                        if( !weapon ) pp *= 2;
                } else {
                        if( weapon ) pp = 0;
                        else pp = skill_power(victim, "unarmed", 
SKILL_USAGE_DEFENSE);
                }

                if( victim->is_busy() ) pp /= 3;
                if( pp < 1 ) pp = 1;

                if( random(ap + pp)< pp ) {

                        parry_skill = victim->query_skill_mapped("parry");
                        if( !parry_skill ) parry_skill = "parry";
           // change to SKILL_D(parry_skill) after added parry msg to those
                        // martial arts that can parry.
                        result += SKILL_D("parry")->query_parry_msg(weapon);

                        if( dp < ap && (!userp(victim) || !userp(me)) 
                        &&      random(your["gin"]*100/your["max_gin"] + 
your["int"]) > 50 ) {
                                your["combat_exp"] += 1;
                                victim->improve_skill("parry", 1);
                        }
                        damage = RESULT_PARRY;

                } else {

                        //
                 //      (5) We hit the victim and the victim failed to parry
                        //

                        damage = me->query_temp("apply/damage");
                        damage = (damage + random(damage)) / 2;
                        if( action["damage"] )
                                damage += action["damage"] * damage / 100;

                        damage_bonus = me->query_str();

                        // Let force skill take effect.
                        if( my["force_factor"] && (my["force"] > 
my["force_factor"]) ) {
                                if( force_skill = 
me->query_skill_mapped("force") ) {
                                        foo = 
SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["force_factor"]);
                                        if( stringp(foo) ) result += foo;
                                        else if( intp(foo) ) damage_bonus += 
foo;
                                }
                        }

                        if( action["force"] )
                                damage_bonus += action["force"] * 
damage_bonus / 100;

                        if( martial_skill = 
me->query_skill_mapped(attack_skill) ) {
                                foo = SKILL_D(martial_skill)->hit_ob(me, 
victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        }

                        // Let weapon or monster have their special damage.
                        if( weapon ) {
                                foo = weapon->hit_ob(me, victim, 
damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        } else {
                                foo = me->hit_ob(me, victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        }

                        if( damage_bonus > 0 )
                                damage += (damage_bonus + 
random(damage_bonus))/2;
                        if( damage < 0 ) damage = 0;

                        // Let combat exp take effect
                        defense_factor = your["combat_exp"];
                        while( random(defense_factor) > my["combat_exp"] ) {
                                damage -= damage / 3;
                                defense_factor /= 2;
                        }

                        //
                        //      (6) Inflict the damage.
                        //

                        damage = victim->receive_damage("kee", damage, me );

                        if( (me->is_killing(victim) || weapon)
                        && random(damage) > 
(int)victim->query_temp("apply/armor") ) {
    // We are sure that damage is greater than victim's armor here.
                                victim->receive_wound("kee",
                                        damage - 
(int)victim->query_temp("apply/armor"), me);
                                wounded = 1;
                        }

                        result += damage_msg(damage, action["damage_type"]);

                        //
                        //      (7) Give experience
                        //

                        if( !userp(me) || !userp(victim) ) {
                                if( (ap < dp)
                                &&      (random(my["gin"]*100/my["max_gin"] + 
my["int"]) > 30) ) {
                                        my["combat_exp"] += 1;
                                        if( my["potential"] - 
my["learned_points"] < 100 )
                                                my["potential"] += 1;
                                        me->improve_skill(attack_skill, 1);
                                }
                                if( random(your["max_kee"] + your["kee"]) < 
damage ) {
                                        your["combat_exp"] += 1;
                                        if( your["potential"] - 
your["learned_points"] < 100 )
                                                your["potential"] += 1;
                                }
                        }
                }
        } 

        result = replace_string( result, "$l", limb );
        if( objectp(weapon) )
                result = replace_string( result, "$w", weapon->name() );
        else if( stringp(action["weapon"]) )
                result = replace_string( result, "$w", action["weapon"] );

        message_vision(result, me, victim );

        if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
                if( damage > 0 )
                        tell_object(me, sprintf( GRN 
"AP：%d，DP：%d，PP：%d，傷害力：%d\n" NOR,
                                ap/100, dp/100, pp/100, damage));
                else
                        tell_object(me, sprintf( GRN 
"AP：%d，DP：%d，PP：%d\n" NOR,
                                ap/100, dp/100, pp/100));
        }

        if( damage > 0 ) {
                report_status(victim, wounded);
                if( victim->is_busy() ) victim->interrupt_me(me);
                if( (!me->is_killing(your["id"])) && 
		    (!victim->is_killing(my["id"])) && 
		    (me->is_fighting(victim)) && 
		    (victim->is_fighting(me)) ) {
                        me->remove_enemy(victim);
                        victim->remove_enemy(me);
                        message_vision( 
winner_msg[random(sizeof(winner_msg))], me, victim);
                }
        }

        if( functionp(action["post_action"]) )
                evaluate( action["post_action"], me, victim, weapon, damage);

        // See if the victim can make a riposte.
        if( attack_type==TYPE_REGULAR
        &&      damage < 1
        &&      victim->query_temp("guarding") ) {
                victim->set_temp("guarding", 0);
                if( random(my["cps"]) < 5 ) {
                        message_vision("$N一擊不中，露出了破綻！\n", me);
                        do_attack(victim, me, victim->query_temp("weapon"), 
TYPE_QUICK);
                } else {
                        message_vision("$N見$n攻擊失誤，趁機發動攻擊！\n", 
victim, me);
                        do_attack(victim, me, victim->query_temp("weapon"), 
TYPE_RIPOSTE);
                }
        }
}

//      fight()
//
//This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
        //object ob;

        if( !living(me) ) return;

        if( !me->visible(victim)
        && (random(100 + (int)me->query_skill("perception")) < 100) )
                return;

// If victim is busy or unconcious, always take the chance to makeanattack.
        if( victim->is_busy() || !living(victim) ) {
                me->set_temp("guarding", 0);
                if( !victim->is_fighting(me) ) victim->fight_ob(me);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

        // Else, see if we are brave enough to make an aggressive action.
        } else if( random( (int)victim->query("cps") * 3 ) < 
((int)me->query("cor") + (int)me->query("bellicosity") / 50) ) {
                me->set_temp("guarding", 0);
                if( !victim->is_fighting(me) ) victim->fight_ob(me);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

        // Else, we just start guarding.
        } else if( !me->query_temp("guarding") ) {
                me->set_temp("guarding", 1);
                message_vision( guard_msg[random(sizeof(guard_msg))], me, 
victim);
                return;
        } else return;
}

//      auto_fight()
//
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
        // Don't let NPC autofight NPC.
        if( !userp(me) && !userp(obj) ) return;

 // Because most of the cases that we cannot start a fight cannot be checked
// before we really call the kill_ob(), so we just make sure we have no 
        // aggressive callout wating here.
        if( me->query_temp("looking_for_trouble") ) return;
        me->set_temp("looking_for_trouble", 1);

        // This call_out gives victim a chance to slip trough the fierce guys.
        call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
        int bellicosity;

        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        bellicosity = (int)me->query("bellicosity");
        message_vision("$N用一種異樣的眼神掃視著在場的每一個人。\n", me);

        if(     (int)me->query("force") > (random(bellicosity) + 
bellicosity)/2 ) return;

        if( bellicosity > (int)me->query("score") 
        &&      !wizardp(obj) ) {
                message_vision("$N對著$n喝道：" + RANK_D->query_self_rude(me)
                        + "看你實在很不順眼，去死吧。\n", me, obj);
                me->kill_ob(obj);
        } else {
                message_vision("$N對著$n喝道：喂！" + RANK_D->query_rude(obj)
                        + "，" + RANK_D->query_self_rude(me) + 
"正想找人打架，陪我玩兩手吧！\n",
                        me, obj);
                me->fight_ob(obj);
        }
}

void start_hatred(object me, object obj)
{
        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?         
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        // We found our hatred! Charge!
        message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, 
obj);
        me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        // We found our vendetta opponent! Charge!
        me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        // We got a nice victim! Kill him/her/it!!!
        me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
        switch(event) {
                case "dead":
                        message_vision("\n$N死了。\n\n", ob);
                        break;
                case "unconcious":
                        
message_vision("\n$N腳下一個不穩，跌在地上一動也不動了。\n\n", ob);
                        break;
                case "revive":
                        message_vision("\n$N慢慢睜開眼睛，清醒了過來。\n\n", 
ob);
                        break;
        }
}

void winner_reward(object killer, object victim)
{
        killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
        int bls;
        string vmark;

// add in May 27, 1996 (1) -- 3 line
	int bonus, exp, pot, score,factor,tfinished;
        //string test;
        mapping quest;

        // Call the mudlib killer apply.
        killer->killed_enemy(victim);

	// added in July 21th, Lingr
	if ( !killer->is_living()  && objectp(killer->query("possessed"))) 
		killer = killer->query("possessed");

        if( userp(victim) ) {
                killer->add("PKS", 1);
                victim->clear_condition();
                // Give the death penalty to the dying user.
                victim->set("bellicosity", 0);
                victim->add("combat_exp", -(int)victim->query("combat_exp") / 
10);
                victim->delete("vendetta");
                if( victim->query("thief") )
                        victim->set("thief", (int)victim->query("thief") / 2);
                if( (int)victim->query("potential") > 
(int)victim->query("learned_points"))
                        victim->add("potential",
                                ((int)victim->query("learned_points") - 
(int)victim->query("potential"))/2 );
                victim->skill_death_penalty();

                bls = 10;
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("%s被%s殺死了。", victim->name(1), 
killer->name(1)));
        } else {
                killer->add("MKS", 1);
                bls = 1;
		
// add in may 27, 1996 (2) -- line (for quest)
		if((quest =  killer->query("quest"))  &&
		   (victim->name(1) == quest["quest"]) &&
		   ((int) killer->query("task_time") >= time())) {
		        tell_object(killer,"恭喜你！你又完成了一項任務！\n");
      			exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
  			pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
     		   	score = quest["score"]/2 + random(quest["score"]/2);
        		factor=killer->query("quest_factor");
        		if (factor) {
                		exp=exp*factor/10;
                		pot=pot*factor/10;
                		score=score*factor/10;
        			}
        
			if (killer->query("score")<0) {
                		score=score*(-1);
        			}
        		bonus = (int) killer->query("combat_exp");
        		bonus += exp;
        		killer->set("combat_exp", bonus);
        		bonus = (int) killer->query("potential");
        		bonus = bonus - (int) killer->query("learned_points");
        		bonus = bonus + pot;
        		if( bonus > 100) bonus = 100;
        		bonus += (int) killer->query("learned_points");
        		killer->set("potential", bonus );
        		bonus = (int) killer->query("score");
        		bonus += score;
        		killer->set("score", bonus);
        		tell_object(killer,HIW"你被獎勵了：\n" +
        		chinese_number(exp) + "點實戰經驗\n"+
        		chinese_number(pot) + "點潛能\n" +
        		chinese_number(score)+"點綜合評價\n"NOR);
        		killer->set("quest", 0 );
			
			tfinished = killer->query("tfinished");
			if (tfinished > 9)
				killer->set("tfinished", 0);
			    else if (tfinished < -10)
				killer->set("tfinished", 1);
				else
					killer->set("tfinished", tfinished+1);	
			}	 
        }

        // NPC got 10 times of bellicosity than user.
        killer->add("bellicosity", bls * (userp(killer)? 1: 10));

        if( stringp(vmark = victim->query("vendetta_mark")) )
                killer->add("vendetta/" + vmark, 1);

//  add in june 25, 1996 (2) -- line (for rebel) 
	if ((string)killer->query("family/master_id") == (string)victim->query("id") && (int)killer->query("family/generation") == (int)victim->query("family/generation") + 1) {
		killer->set("betrayer",killer->query("betrayer")-1);
		killer->set("title","普通百姓");
		killer->set("family",0);
		}
}
 
