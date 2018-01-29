#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void create()
{
        set_name( "老者", ({ "old man", "man", "old" }) );
        if( !restore() ) {
                set("short", "在桐柏山中採藥的" HIC "老者" NOR "(old man)");
                set("long",
                        "他白髮蒼蒼,老態龍鍾.\n"
                        "他終年採藥於深山，當有些不同凡響之處。\n"
                        "他寬五尺，高三尺.你實在無法理解他怎麼這麼的胖。\n" );
                set("gender", "男性" );
                set("chat_chance", 70);
                set("chat_msg", ({
                        (: this_object(), "random_move" :),
                        CYN "老者說道：哎。。。你這可憐的孩子，餓得面黃肌瘦的。\n" NOR,
                        CYN "老者撫摸着你的頭，老淚縱橫。\n" NOR,
                        CYN "老者拈起衣角擦了擦眼角的濁淚。\n" NOR,
               }) );
                set("chat_msg_coombat", ({
                        CYN "\n老者說道：山藥蛋!!我們愛吃!!!!!!\n" NOR,
                        CYN "\n老者說道：你這孩子長得多象山藥蛋啊。\n" NOR,
                }) );

                set("pills", 9);

                // This is the initial apply for his race.
                set("perm_apply", ([
                        "attack":       10,
                        "dodge":        10,
                        "damage":       5,
                ]) );

                set("age", 99);
                set("str", 44);
                set("cor", 24);
                set("cps", 18);
                set("per", 24);
                set("int", 42);
                set_skill("unarmed", 1);
                set_skill("dodge", 150);
                set_skill("force", 1);
                set_skill("parry", 1);
        }

        set_temp("apply", query("perm_apply"));
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}
void greeting(object ob)
{   string item;  
    object foods;
 
 item = "tomatoo";  

 if( !ob || environment(ob)!=environment() ) return;   
 else if( objectp(foods = present(item, ob)) )  {
                tell_object(ob, "我給你的山藥蛋好吃嗎??\n" NOR );
        }  else  {
                  command("sigh");
                  message_vision("老者撫摸着$N的頭，老淚縱橫。\n 說道: " +
          "說道：哎。。。$N這可憐的孩子，餓得面黃肌瘦的。\n" +
          "老者哆哆嗦嗦從懷裏拿出個小布包，打開一層又一層，打開一層又一層.." +
          "最後拿出個小山藥蛋塞到$N手裏。\n",ob);   
                foods = new("/d/choyin/npc/obj/tomatoo");
                foods->move(ob);
                ob->set_temp("choyin/山藥蛋", 1);
                  }
 return;              
}        




void reset()
{
        int learn;

   
        set("pills", 9);
        if( (int)query("potential") > (int)query("learned_points") ) {
                learn = (int)query("potential") - (int)query("learned_points");
                add_temp("apply/attack", learn / 3);
                add_temp("apply/dodge", learn / 3);
                add_temp("apply/damage", learn / 3);
                add("learned_points", (learn / 3) * 3);
        }

        save();
}

int accept_fight(object who)
{
set("short", "桐柏山妖  山藥蛋(yam)"); 
        if( is_fighting() ) {
                if( random(query("eff_kee")) > (int)query("kee") ) {
                        say( CYN "老者顫聲道：我這一把年紀，哎！老者氣得幾乎暈倒在地。\n" NOR);
                        return 0;
                } else {
                        say( CYN "老者正色道：我得管教管教你！！\n" NOR);
                        return 1;
                }
        }
        return 1;
}

int receive_damage(string type, int pts)
{
        int damage;

        damage = ::receive_damage(type, pts);
        if( (type=="kee") && (damage > (int)query("max_kee") / 5) ) {
                say( CYN "老者捂著受傷的地方，白髮散亂，勉強穩住身行。\n" NOR);
                if( random(query("kee")) < damage)
                        random_move();
        }

        if( (int)query("pills")
        &&      (((int)query("kee")) < 20
                || ((int)query("gin") < 20)
                || ((int)query("sen") < 20) )) {
                say( HIY "老者從口袋摸出一粒象小山藥蛋的仙豆吞了下去。\n
" NOR);
                set("gin", query("eff_gin"));
                set("kee", query("eff_kee"));
                set("sen", query("eff_sen"));
                add("pills", -1);
        }
        return damage;
}

varargs void improve_skill(string skill, int amount, int raw)
{
        // Thus we can gain skill levels from direct fighting.
        ::improve_skill(skill, amount);
}

void revive()
{
        // This is a feature of sungoku's race. See the comic :P.
        add("combat_exp", (int)query("combat_exp") / 3 + 10);
        reset();
        ::revive();
}

void kill_ob(object ob)
{   object me;
        me=this_player();      
        set("short", "桐柏山妖  山藥蛋(yam)"); 

        message_vision("採藥老者眼放異光，說道：你真的不喜歡山藥蛋嗎??\n\n"
+ "沉吟半響道：既然如此，老頭子今天豁出去了，納命來！\n" + "山藥蛋雙手一招，一團黑霧涌起......\n",me);
        message_vision("只聽見「砰」地一聲，$N像一捆稻草般飛了出去！！\n",me);
        message_vision("$N死了。\n\n",me);
        message_vision(HIW"鬼門關 \n",me);
        message_vision("    這裏就是著名的陰間入口「鬼門關」，在你面前矗立著一座高大的\n",me);
        message_vision("黑色城樓，許多亡魂正哭哭啼啼地列隊前進，因爲一進鬼門關就無法再\n",me);
        message_vision("回陽間了。\n",me);
        message_vision("    這裏明顯的出口是 north 和 south。\n",me);
        message_vision("黑無常(black gargoyle)\n",me);
        message_vision("黑無常發出一陣像呻吟的聲音，當他發現你正注視著他的時候，瞪了你一眼。\n",me);
        message_vision("黑無常說道：喂！新來的，你叫什麼名字？ \n\n",me);
        message_vision("黑無常「哼」的一聲，從袖中掏出一本像帳冊的東西翻看著。\n\n",me);
        message_vision("黑無常閣上冊子，說道：咦？陽壽未盡？怎麼可能？\n\n",me);
        message_vision("黑無常搔了搔頭，嘆道：罷了罷了，你走吧。\n\n",me);
        message_vision("一股陰冷的濃霧突然出現，很快地包圍了你。\n\n",me);
        message_vision("$N覺得有什麼地方不對了，使勁掐了一下自己，＄N慘叫了一聲:哇，好痛啊～～～～～～\n",me);
        message_vision("$N出竅的真魂繞了一大圈，終於歸位了。\n",me);
        message_vision("黑霧慢慢消散了\n",me);
        message_vision("山藥蛋就地一滾，沒入土中不見了......\n"NOR,me);
        destruct(this_object());                   
        return 0;


}
void defeated_enemy(object ob)
{       command("fear"); 
        say(CYN "老者骨碌碌就地打了個滾，說道：我贏了！" NOR);
        remove_killer(ob);
}      



