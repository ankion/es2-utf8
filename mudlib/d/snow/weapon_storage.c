// Room: /d/snow/weapon_storage.c

inherit ROOM;

void create()
{
	set("short", "兵器儲藏室");
	set("long", @LONG
這是一間堆滿各式兵器、刀械的儲藏室，各式武器都依照種類、長
短、依次放在一起，並且擦拭得一塵不染，儲藏室的出口在你的南邊，
面對出口的左手邊有一個架子(shelf)。
LONG
	);
	set("exits", ([
		"south" : __DIR__"school2",
	]));
	set("objects", ([
		__DIR__"npc/obj/bamboo_sword": 1,
	]) );
	set("item_desc", ([
		"shelf": "這個架子上空蕩蕩的，什麼都沒有。\n"
	]) );

	setup();
}

void init()
{
	add_action("do_push", "push");
}

void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==3
	&&	!query("exits/down") ) {
		message("vision", "地板忽然發出軋軋的聲音，一塊地面緩緩移動著，露出一個向下的階梯。\n",
			this_object() );
		set("exits/down", __DIR__"secret_storage");
		if( room = find_object(__DIR__"secret_storage") ) {
			room->set("exits/up", __FILE__);
			message("vision", "天花板忽然發出軋軋的聲音，露出一個向上的階梯。\n", room );
		}
		delete("left_trigger");
		call_out("close_passage", 10);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "地板忽然發出軋軋的聲音，一塊地面緩緩移動著，將向下的通道蓋\住了。\n",
		this_object() );
	if( room = find_object(__DIR__"secret_storage") ) {
		room->delete("exits/up");
		message("vision", "天花板忽然發出軋軋的聲音，向上的階梯又緩緩地收了回去。\n",
			room );
	}
	delete("exits/down");
}


int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="shelf" ) {
		write("你試著推動這個架子，似乎可以左右滑動....\n");
		return 1;
	}

    message_vision("$N將架子往左推...，忽然「喀」一聲架子又移回原位。\n", this_player());
    add("left_trigger", 1);
    check_trigger();
    return 1;
}


void reset()
{
	::reset();
	delete("left_trigger");
}
