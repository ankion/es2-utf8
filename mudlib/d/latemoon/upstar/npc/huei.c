inherit NPC;
 
void create()
{
        set_name("邢千慧", ({ "huei","girl" }) );
        set("gender", "女性" );
        set("age", 27);
        set("long", @TEXT
她國色天香，嬌麗無倫；溫柔嫺靜，秀絕人寰。
她姿容絕美，世所罕見。從她身旁你聞道一寒谷
幽香。
TEXT
);
       set("class", "dancer");
       set("combat_exp", 250000);
        set_skill("unarmed", 50);
        set_skill("dodge", 70);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 70);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 1000);
        set("max_force", 500);
       set_temp("apply/armor", 70);
       set_temp("apply/attack", 50);

        create_family("晚月莊",2,"弟子");
        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/redbelt")->wear();
        carry_object("/d/latemoon/obj/clasp")->wear();
}

