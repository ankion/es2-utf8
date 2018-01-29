// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "說道：您太客氣了，這怎麼敢當？\n",
        "像是受寵若驚一樣，說道：請教？這怎麼敢當？\n",
        "笑著說道：您見笑了，我這點雕蟲小技怎夠資格「指點」您什麼？\n",
});

int is_appr_of(object me, object master);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string skill, teacher, master;
        object ob, *list , couple_ob;
        int master_skill, my_skill, gin_cost;
	string target, cardname;
	int i,marry_flag;

        if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
                return notify_fail("指令格式：learn <技能> from <某人>\n");

        if( me->is_fighting() )
                return notify_fail("臨陣磨槍？來不及啦。\n");

        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("你要向誰求教？\n");

        if( !living(ob) )
                return notify_fail("嗯....你得先把" + ob->name() + 
"弄醒再說。\n");

	marry_flag = 0;
	list = all_inventory(me);
	i = sizeof(list);
	while (i--) {
		if ((string)list[i]->query("id") == "marrycard") {
			cardname = list[i]->query("name");
			marry_flag = 1;
		}
	}
	if ( marry_flag ==1 ) {	
		if (sscanf(cardname,"你和%s的婚約" ,target)!=1)
                	return notify_fail("你沒有伴侶.\n");
			couple_ob = find_player(target);	
	}
 
       
	// if( !me->is_apprentice_of(ob) ) {
	if (!is_appr_of(me, ob)) {
		if (couple_ob != ob) {
                if( (string)me->query("family/family_name") != 
(string)ob->query("family/family_name")
                ||      (int)ob->query("family/privs") != -1 ) {
                        notify_fail( ob ->name() + 
reject_msg[random(sizeof(reject_msg))] );
                        if( !(ob->recognize_apprentice(me)) ) return 0;
                }
		}
        }

        if( !master_skill = ob->query_skill(skill, 1) )
                return notify_fail("這項技能你恐怕必須找別人學了。\n");

        notify_fail(ob->name() + "不願意教你這項技能。\n");
        if( ob->prevent_learn(me, skill) )
                return 0;

        my_skill = me->query_skill(skill, 1);
        if( my_skill >= master_skill )
                return notify_fail("這項技能你的程度已經不輸你師父了。\n");

        notify_fail("依你目前的能力，沒有辦法學習這種技能。\n");
        if( !SKILL_D(skill)->valid_learn(me) ) return 0;

        gin_cost = 150 / (int)ob->query("int") + 150 / (int)me->query("int");

        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }

        if( (int)me->query("learned_points") >= (int)me->query("potential") )
                return 
notify_fail("你的潛能已經發揮到極限了，沒有辦法再成長了。\n");
        printf("你向%s請教有關「%s」的疑問。\n", ob->name(),
                to_chinese(skill));

        if( ob->query("env/no_teach") )
                return notify_fail("但是" + ob->name() + 
"現在並不準備回答你的問題。\n");

        tell_object(ob, sprintf("%s向你請教有關「%s」的問題。\n",
                me->name(), to_chinese(skill)));

        if( (int)ob->query("sen") > gin_cost/5 + 1 ) {
                if( userp(ob) ) ob->receive_damage("sen", gin_cost/5 + 1);
        } else {
                write("但是" + ob->name() + 
"顯然太累了，沒有辦法教你什麼。\n");
                tell_object(ob, "但是你太累了，沒有辦法教" + me->name() + 
"。\n");
                return 1;
        }
                

        if( (int)me->query("gin") > gin_cost ) {
                if( (string)SKILL_D(skill)->type()=="martial"
                &&      my_skill * my_skill * my_skill / 10 > 
(int)me->query("combat_exp") ) {
                        
printf("也許是缺乏實戰經驗，你對%s的回答總是無法領會。\n", ob->name() );
                } else {
                        printf("你聽了%s的指導，似乎有些心得。\n", 
ob->name());
                        me->add("learned_points", 1);
				me->improve_skill(skill, random(me->query("int")+me->query("combat_exp")/(1000+me->query("combat_exp")/1000)));
	
                }
        } else {
                gin_cost = me->query("gin");
                write("你今天太累了，結果什麼也沒有學到。\n");
        }

        me->receive_damage("gin", gin_cost );

        return 1;
}

int is_appr_of(object me, object master)
{
	if (me->query("family/master_id") != master->query("id"))
		return 0;

	if (me->query("family/generation") != master->query("family/generation")+1) {
		message_vision("$n看起來要殺死$N\n",master,me);
		return 0;
		}

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : learn <技能> from <某人>
 
這個指令可以讓你向別人請教有關某一種技能的疑難問題，當然，你請教的對象在這
項技能上的造詣必須比你高，而你經由這種方式學習得來的技能也不可能高於你所請
教的人，然而因爲這種學習方式相當於一種「經驗的傳承」，因此學習可以說是熟悉
一種新技能最快的方法。

通常，一個人剛學到一種新技能是不會有什麼疑難問題的，而是經由實際上的應用中
遭遇問題，這些問題對於學習一種新技能的過程是很重要的，尤其是各種作爲其他技
能基礎的基本技能，更需要經由「發現問題—解決問題」的過程才能得到較好的效果
因此我們將這種發現問題的過程用「潛能」的觀念表示，一個人能夠自己發現某些問
題，表示他(她)有解決這項問題的潛能，當你具有這樣的潛能時就可以利用這個指令
來向其他人請教，而獲得進步。
(PS. 潛能還有其他更廣義的定義，這裏只是其中之一 )

此外學習也需要消耗一些精力，而消耗的精力跟你自己、與你學習對象的悟性有關。

至於如何知道你能從對方學到什麼技能，如果對方是你的師父，可以用 skills 指令
直接查看，如果不是你的師父，那麼通常會有其他的提示，你只好自己想辦法。

其他相關指令 : practice、study
HELP
        );
        return 1;
}
 
