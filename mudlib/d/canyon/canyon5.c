// ROOM:__DIR__"canyon5"

inherit ROOM;
void create()
{
        set("short","關外小路");
	set("long",@LONG                                   
南邊即爲天駝關的關口，兩片諾大的鐵門(door)，若非由關內打開恐
怕難以進入，往東側看去，鐵柵的映滿你整雙眼眸，轉向西側，看到的還
是一片光禿禿的山壁，不由得使你想早點離開這個地方。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
		"south" : __DIR__"canyon6",	
		"north" : __DIR__"canyon4",
	]) ); //eof(exits)

	set("item_desc", ([
		"door": "這巨大的鐵門鏽跡斑斑，它是上下開合的，現在已經高高的擡起，\n"
			"若它失控砸下，可能什麼東西都會被砸扁。\n",
	]) );	
	setup();
	
	replace_program(ROOM);
} //EOF
