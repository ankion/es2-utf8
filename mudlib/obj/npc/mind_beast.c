// mind_beast.c

inherit NPC;

void create()
{
	set_name("觀想獸", ({ "mind beast", "beast" }) );
	set("race", "野獸");
	set("age", 3);
	set("long", "這是一隻由修道人的雜念綺思所化的觀想獸，會纏住人的魂魄。\n");
	
	set("str", 48);
	set("cor", 52);
	set("cps", 22);

	set("max_kee", 600);
	set("max_gin", 600);
	set("max_sen", 900);

	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	if( this_player() ) {
		set("combat_exp", this_player()->query_skill("spells", 1) * 2000);
		set("bellicosity", this_player()->query("bellicosity") );
	}
	
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);

	setup();
}

void die()
{
	string owner;
	object owner_ob;

	owner = query("owner");

	if( objectp(owner_ob = find_player(owner)) ) {
		if( (object)query_temp("last_damage_from") != owner_ob ) {
			tell_object(owner_ob, "你的觀想獸被人殺死了！\n你覺得一陣天旋地轉....\n");
			owner_ob->unconcious();
		} else {
			tell_object(owner_ob, "你殺死了你的觀想獸，並且從中悟到了一些咒術的道理。\n");
			owner_ob->improve_skill("spells", random(owner_ob->query("spi"))+1);
		}
	}
	::die();
}
