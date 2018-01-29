// magistrate_waiter.c

#include <command.h>
inherit NPC;

int do_nod(string);
void remove_effect(object);
void go_in();
void greeting(object);

void create()
{
        set_name("帶刀侍衛", ({ "magistrate waiter","waiter" }) );
        set("gender", "男性" );
        set("age", 44);
        set("str", 45);
        set("cor", 28);
        set("cps", 18);
        set("int", 10);
        set("per", 10);
        set("long", @LONG
帶刀侍衛皆爲槐陽王程老王爺麾下驍將,身負絕藝.
LONG
);
        set("combat_exp", 1000000);
        set("attitude", "heroism");
        set_skill("blade",120); 
        set_skill("parry", 80);
        set_skill("dodge", 120);
        set_skill("fall-steps",120);
        set_skill("shortsong-blade",150);
        map_skill("blade","shortsong-blade");  
        map_skill("dodge","fall-steps");  
        set("pending/charge",0);
        setup();
        add_money("silver",40);
        carry_object(__DIR__"obj/blade")->wield(); 
        carry_object("/obj/cloth")->wear();        
}

void greeting(object who)
{
return_home(find_object("/d/choyin/yamen.c"));
command("open door");
command("go south");           //這些走法與路徑有關
command("go south");
if (!find_player(who->query("id"))||environment()!=environment(who))
        {
                say("奇怪，剛纔是誰啊？\n");
                go_in();
        }
who->delete_temp("have_beat_drum");
add("pending/charge",1);
if (query("pending/charge")>20)
        {
        say("老爺今天太累了，請明天再來吧。\n");
        call_out("go_in",10);
        return;
        }
message_vision("$N從衙門內院走了出來，看了看$n，說道：是你擊鼓申冤嗎？(yes/no)\n
",this_object(),who);
set_temp("pending/beat",who);
add_action("do_nod",({"yes","no"}));
call_out("remove_effect",who->query("score")/100+10,who->query("id"));
}

int do_nod(string arg)
{
object who,waiter;
who=this_player();
waiter=this_object();
if (who!=query_temp("pending/beat"))
        return notify_fail("沒說你呢！搗什麼亂！去去去...一邊呆着！\n" );
remove_call_out("remove_effect");
if (query_verb()=="no")
        {
        write(waiter->query("name")+"雙眼一瞪，喝道：沒冤情你擊什麼鼓？！\n");
        COMBAT_D->do_attack(this_object(),who);
        write("一邊涼快涼快.\n");
        COMBAT_D->do_attack(this_object(),who);
        who->move(find_object("/d/choyin/yamen_yard.c"));
        delete_temp("pending/beat");
        go_in();
        return 1;
        }
else
        {
        who->set_leader(waiter);
        command("hmm");
        say("好吧，跟我來....\n");
        GO_CMD->main(this_object(),"east");
        command("close door");
        call_out("greeting2",3,who);
        return 1;
        }
}

void remove_effect(string quire)
{
if (file_name(environment())!="/d/choyin/court1")
        return;
if (objectp(find_player(quire))&&environment()==environment(find_player(quire)))
        {
        say(RANK_D->query_self_rude(this_object())+"沒功夫和你羅嗦！！\n");
        delete_temp("pending/beat");
        go_in();
        }
return;
}

void go_in()
{
        move(find_object("/d/choyin/yamen_yard.c"));
        command("close door");
        return_home(find_object("/d/choyin/yamen.c"));
        return;
}

void greeting2(object who)
{
        write(this_object()->query("name")+"高聲說道, 老爺......我把擊鼓人帶上來
了！.....\n");
        say("老爺就在堂上，這邊走......\n");
        command("go north");
        who->set_leader(0);
        tell_object(who,"到了，......有冤就申(charge)吧。\n");
}
