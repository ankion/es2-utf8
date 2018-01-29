// Room: /d/city/jitan.c

inherit ROOM;

void create()
{
	set("short", "祭壇");
	set("long", @LONG
這是一片寬闊的小廣場，廣場的中間是皇家的祭壇(altar)，每年
朝廷慶祝豐收或祈禱的重大典禮都在這裏舉行，皇上、皇后和文武百
官能上祭壇，其他人只能從旁邊繞過去。除了禁衛軍的官兵和宮裏的
雜役偶爾出入外，很少有人來往。往南是紫禁城的神武門，北面是一
個非常熱鬧的十字路口。
LONG
	);
	set("exits", ([
		"south" : "/d/city/shenwumen",
		"north" : "/d/city/street7",
	]));
	set("item_desc", ([
		"altar": 
	"園祭壇的欄杆是用漢白玉作成的，壇面由精細磨過的花崗岩鋪成，中\n"
	"間有個臺子(platform)。\n",
		"platform": 
	"只有皇帝能站在這個漢白玉臺子上面，隱約地你好象看到臺子的下面\n"
	"有個凸起(sth)。\n",
		"sth": 
	"這很象一個按鈕(button)，上面長着細細的青苔，你突然一陣莫名其\n"
	"妙的緊張，好奇心卻驅使你摸摸這個按鈕，你發現它可以按(press)，\n"
	"也可以旋轉(turn)。\n"
	]) );

	setup();
}

void init()
{
	add_action("do_turn", "turn");
	add_action("do_press", "press");
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "地板忽然發出軋軋的聲音，一塊地面緩緩移動著，將向下的通道蓋\住了。\n",
		this_object() );
	if( room = find_object("/d/city/midao1") ) {
		room->delete("exits/up");
		message("vision", "天花板忽然發出軋軋的聲音，向上的階梯又緩緩地收了回去。\n",
			room );
	}
	delete("exits/down");
}

int do_turn(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="button" ) {
		write("你轉了轉這個按鈕，它順時針和逆時針方向都能轉動。\n");
		return 1;
	}
	if( sscanf(arg, "button %s", dir)==1 ) {
		if( dir=="forward" ) {
			message_vision("$N將按鈕沿順時針轉了一圈，什麼事情也沒發生。\n", this_player());
			add("forward", 1);
			return 1;
		} else if( dir=="backward" ) {
			message_vision("$N將按鈕沿逆時針轉了一圈，什麼事情也沒發生。\n$N忽然打了個冷顫，可能是心裏害怕了。\n", this_player());
			add("backward", 1);
			return 1;
		} else {
			write("你想讓它順時針(forward)轉還是逆時針(backward)轉？\n");
			return 1;
		}
	}
}


int do_press(string arg)
{
	string dir;
	object room;

	if( !arg || arg=="" ) return 0;

	if( arg=="button" ){ //return 0;

	if( (int)query("forward")==1
	&&	(int)query("backward")==3
	&&	!query("exits/down") ) {
		message("vision", "地板忽然發出軋軋的聲音，一塊地面緩緩移動著，露出一個向下的階梯。\n",
			this_object() );
		set("exits/down", "/d/city/midao1");
		if( room = find_object("/d/city/midao1") ) {
			room->set("exits/up", __FILE__);
			message("vision", "天花板忽然發出軋軋的聲音，露出一個向上的階梯。\n",
				room );
		}
		delete("forward");
		delete("backward");
		call_out("close_passage", 3);
	}
	return 1;}
}


void reset()
{
	::reset();
	delete("forward");
	delete("backward");
}
