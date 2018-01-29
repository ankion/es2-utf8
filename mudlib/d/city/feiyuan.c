// /d/city/feiyuan

inherit ROOM;

int do_find ();

void create()
{
        set("short", "廢園");
        set("long", @LONG
你來到一所廢園裏。據說廢園的主人原也是位極人臣的，後來卻
以「莫須有」的罪名被皇上斬了全族，其他的官員怕晦氣，都不敢來
此住，遂形成廢園。廢園裏荒草叢生，往日的輝煌已不再現，僅留下
幾個殘垣供人憑弔。
LONG
        );

        set("exits", ([
                "south" :       __DIR__"street6",
                ]));

        setup();
}

void init ()
{
	add_action ("do_find", "find");
}

int valid_leave(object me,string dir)
{
        if ( dir=="south" )
		tell_object(me, "突然你眼前似乎有什麼東西一閃，然後又消失在草叢\n中。回去在草叢中找找（find）？\n\n\n");

        return ::valid_leave(me,dir);
}

int do_find ()
{
	object *list, me, token;
	int i;

	me = this_player ();

	list = all_inventory(me);
	i = sizeof(list);
        while (i--) {
              if (((string)list[i]->query("id")) == "token")
			return notify_fail("忙活了半天，沒有什麼新的發現。\n");
		}

	if (random(me->query("kar") + 30) >= 35) {
		token = new(__DIR__"obj/token");
		token->move(me);
		message_vision("$N竟找到了一個出城令。\n", me);
		return 1;
		}

	return notify_fail ("白忙了半天，一無所獲。\n");
}


