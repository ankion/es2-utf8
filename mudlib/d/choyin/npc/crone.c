// crone.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("乾癟老太婆", ({ "crone" }) );
	set("gender", "女性" );
	set("age", 73);
	set("long",
		"這個老太婆懷中抱了個竹簍，似乎在賣什麼東西，也許\你可以跟她問問\n"
		"價錢？\n");
	set("attitude", "friendly");
	set("inquiry", ([
		"年齡": "老身今年七十有八啦。\n",
		"here":	"這一帶我可熟了。\n",
		"忘憂草": "老身隱隱約約地聽說過什麼‘草’啊，‘獅子’的，具體的也就不知了。\n",
		]) );

	set("vendor_goods", ([
		"amulet": "/d/choyin/npc/obj/amulet",
		"red guay": "/d/choyin/npc/obj/red_guay",
	]) );
	setup();
}

void init()
{	
	::init();

	add_action("do_vendor_list", "list");
}

void relay_ask(object me, string topic)
{
	command("?");
	command("say 對不起，老婆子耳背，" + RANK_D->query_respect(me) + "您是想"
		"買東西吧？這兒有價錢(list) ....\n");
	message("vision", "老太婆打開竹簍，蓋\子上貼了張紙片。\n", environment(me));
}
