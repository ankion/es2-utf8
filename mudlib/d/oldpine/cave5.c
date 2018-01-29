// Room: /d/oldpine/cave5.c

inherit ROOM;

string look_wall ();

void create()
{
	set("short", "山洞");
	set("long", @LONG
你現在已經到達山洞的深處了, 耶...東面就是洞口了, 還可以聽
見外面瀑布的水聲, 仔細的觀察石壁(wall), 可以發現上面有一些用利
劍雕刻的字....
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"waterfall",
		]));

	set("item_desc", ([
		"wall" : (: look_wall :),
		]) );

	set("objects", ([
		__DIR__"npc/skeleton":	1,
		]) );

	setup();
}

void init ()
{
	add_action ("do_bury", "bury");
}

int do_bury (string arg)
{
	object obbook, obsk;
	int ikar;
 
        if( !arg ) return notify_fail("你要埋什麼？\n");
        if( arg != "skeleton" || !objectp(obsk = present(arg, environment(this_player()))) )
                return notify_fail("這裏沒有這樣東西。\n");

	message_vision ("$N小心翼翼地埋好了那具骸骨。\n",this_player());

	obsk->move("/obj/void");

	ikar = (int ) random((int) (this_player()->query("kar"))+10); 
	if (ikar > 25) { 
		message_vision("$N聽見山洞頂部的石壁「喀喇」地一聲響，一本書墜落下來。\n", this_player());
		obbook = new(__DIR__"npc/obj/parrybook");
		obbook->move(__DIR__"cave5");
		return 1;
		}
	    else if (ikar > 20) 
		message_vision("$N只看見山洞頂部紛紛揚揚飄下幾張紙片來。\n",this_player());
			
	message_vision ("$N聽得「轟」的一聲響，已經從這摔了下去\n", this_player());
	this_player()->move(__DIR__"waterfall");
	
	return 1;
}

string look_wall ()
{
	return ("老夫南危水, 乃是昔年水煙閣五長老中第一高手,
一生醉心武學, 集天邪、封山兩派之所長, 爲營救盟主遭小人暗算,
埋骨於此。男子漢大丈夫死不足惜, 只可恨一身武學尚無傳人!
葬(bury)我遺骨者老夫將贈以過招要旨, 唉......
");
} 
