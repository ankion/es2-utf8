// glass.c

inherit EQUIP;

void create()
{
	set_name("戰鬥力探測器", ({ "detector", "glass", "device" }) );
	set_weight(300);
	set("unit", "個");
	set("long",
		"這是來自「七龍珠」的戰鬥力探測器，你可以用它來探測(detect)別人\n"
		"的戰鬥力。\n");
	set("value", 500);
	set("type", "misc");
	set("apply", ([
		"頭部":	0,
	]) );
}

void init()
{
	add_action("do_detect", "detect");
}

int do_detect(string arg)
{
	object ob;
	int sen, sk;
	string skill;

	if( arg ) ob = present(arg, environment(this_player()));
	else ob = this_player()->query_opponent();

	if( !ob ) return notify_fail("你要探測誰的戰鬥力？\n");

	sen = (int)ob->query("sen");
	if( stringp(skill = ob->query("attack_skill")) )
		sk = ob->query_skill(skill);
	else
		sk = 0;

	printf("探測器顯示%s的戰鬥力是：%d\n",
		ob->query("name"), 
		(sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("combat_exp") );

	return 1;
}

