// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "侮天鬼王" NOR, ({ "demogorgon" }) );
	set("long",
		"侮天鬼王神情倨傲地站在你面前，他高大的身軀跟一股令人窒息的\n"
		"可怕殺氣正壓得你幾乎喘不過氣來，你的心裏似乎有一個聲音在告\n"
		"訴你：「 快 逃 ！！」\n");

	set("age", 7006);
	set("pursuer", 1);

	set("max_gin", 5000);
	set("max_kee", 5000);
	set("max_sen", 5000);

	set("max_atman", 9999);
	set("atman", 9999);
	set("max_force", 5000);
	set("force", 5000);
	set("max_mana", 5000);
	set("mana", 5000);

	set("str", 100);
	set("cor", 100);
	set("cps", 100);
	set("spi", 100);
	set("int", 100);
	set("con", 100);
	set("kar", 0);
	set("per", 0);

	set("combat_exp", 5000000);

	set_skill("staff", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	setup();

	carry_object(__DIR__"obj/demon_staff")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;

	message("system",
		HIR "\n你聽到天空中傳來一陣可怕的咆哮 ....\n\n"
		HIW	"侮天鬼王" HIR "用震耳欲聾的聲音喝道：\n\n"
			"\t\t全 天 下 的 衆 生 給 我 聽 著 ！\n\n"
			"\t\t限你們十五分鐘內把我的頭顱交出來 ！\n\n"
			"\t\t不 然 的 話 ..... 哼 .. 哼 ！\n\n" NOR,
		users() );
	call_out("countdown", 60, 15);
}

void countdown(int min)
{
	min--;
	if( min ) {
		message("system",
			HIW "\n侮天鬼王" HIR "用震耳欲聾的聲音喝道：\n\n"
				"\t\t你們還有" + chinese_number(min) + "分鐘的時間交出我的頭顱！\n\n"
				"\t\t—不—要—命—的—就—給—我—慢—慢—拖—吧—！\n\n" NOR,
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
			HIW "\n侮天鬼王" HIR "用震耳欲聾的聲音喝道：\n\n"
				"\t\t可恨.....真是可恨....\n\n"
				"\t\t蒼天啊～ 大地啊～  海洋啊～  衆生啊～\n\n" NOR,
			users() );
		call_out("do_shutdown", 3);
	}
}

void do_shutdown()
{
	message("system",
		HIW "\n\n侮天鬼王" HIR "用震耳欲聾的聲音喝道：\n\n"
		HIW "\t\t通 通 和 我 一 起 下 地 獄 吧 ～～～～ ！\n\n"
		HIR "\t\t聲音一畢，天空立刻變得血紅，不....你眼前的一切都變得血紅...\n\n"
			"\t\t所有的一切都在瞬間陷入火海....\n\n"
			"\t\t然後你的眼前是一片黑暗....無止盡的黑暗....\n\n" NOR,
		users() );
	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);

	if( !ob ) return;

	message("system",
		HIR "\n\n你聽到一聲帶著憤恨、驚恐、與野獸般的咆哮聲響徹整個天空。\n\n"
		HIW "侮天鬼王" HIR "嘶啞地吼著：可惡的" + ob->name(1) + "，我一定會報仇的～～～\n\n"
			"然後一道黑色火焰呼嘯著衝上雲端，大地又恢復了寧靜。\n\n" NOR,
		users() );
	destruct(this_object());
}
