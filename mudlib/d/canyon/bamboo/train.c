// Room: /d/canyon/bamboo/train.c

inherit ROOM;

void create()
{
	set("short", "洞內石室");
	set("long", @LONG
颼颼的風不停地向你身上襲捲而來，石室的四周竟有四個大洞各
分佈東南西北四方，向洞外望去亦是一遍遍的竹林，和之前的竹林只
差在於風勢的大小，強風無情的猛擊挺立的竹子，竹子左右搖晃的抵
抗著，正是一幅柔以破剛之圖，壁上有一石制書櫃(bookcase)，正散
出陣陣的藍光，和之前所遇之正氣一脈相連，匣中似有一物，看來才
是正氣的來源。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"bamboo3",
]));

        set("item_desc", ([
        "bookcase" : "看起來是個普普通通的櫃子，或許\你可以search看看。\n",
	]) );

	setup();
}

void init()
{
	add_action("search_case","search");
}

int search_case(string arg)
{
	object me,obj;
	
	if ( !arg || (arg!="bookcase") ) return 0;
	
	me=this_player();
	if ( query_temp("got") ) {
		message_vision("$N在書櫃找了找但沒找到些什麼\n",me); 
		return 1;
	}
	
	message_vision("$N在書櫃中找了到一個書匣\n",me);
	obj=new(__DIR__"obj/slipcase");
	obj->move(me);
	set_temp("got", 1);
	return 1;
}	
	
