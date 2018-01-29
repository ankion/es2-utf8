// Room: /d/village/lordhouse3.c

inherit ROOM;
string look_shield();

void create()
{
	set("short", "財主家南房");
	set("long", @LONG
南房佈置得象個書房，在屋子的中間有一張大書桌，靠西側的牆上立
着一個書架(shield)，上面很擺了幾本書。向南和向西開了兩面大窗戶，
向南望去，能模模糊糊地望見京城林立的樓閣；向西可以看到在田間忙碌
的田農。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lordhouse1",
]));
	set("item_desc",([
	//	"shield": "這書架上好象擺着八本書，你可以將它們中的某一本抽(take)出來，\n或將抽出來的書放回去(putback)。\n",
		"shield": look_shield(),
	]) );
	
	set("no_clean_up", 0);

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_takeout","take_out");
	add_action("do_push","push");
}

int do_takeout(string arg)
{
	object room;
	string num;
	
	if( !arg || arg=="" )
		return notify_fail("你要拿什麼？\n");
	if( arg=="book" ) {
	write("你想拿第幾本石書？\n");
	return 1;
	}
	
	if( sscanf(arg, "book %s", num)==1 ) {
	    if( num <"0" || num >"12" ){
	    	return notify_fail("有多少本書，你仔細點清楚了！\n");
	    }
	    switch( num ){
	    	case "9":
		    if( (int)query("key")==0 )
		    	add("key",1);
		    else
		    	add("key",6);
		    break;
	    	case "3":
		    if( (int)query("key")==1 )
			add("key",1);
		    else
			add("key",6);
		    break;
		case "11":
		    if( (int)query("key")==2 )
			add("key",1);
		    else
			add("key",6);
		    break;
		case "6":
		    break;
//		    if( (int)query("key")==3 ){
//		    	if( room = find_object("/d/village/lordhouse2") )
		   
		    }
	    }
	}

	return 1;
}

string look_shield()
{
//	string book[16];
	int iCount;
	return "are this true?\n";
}
