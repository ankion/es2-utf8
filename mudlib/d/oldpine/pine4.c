// Room: /d/oldpine/pine1.c

inherit ROOM;

void create()
{
	set("short", "松樹林");
	set("long", @LONG
你現在正站在一個松樹林裏，嗯....這是一個松樹林....你所知就
這麼多，茂密的松樹遮蔽了整個天空，使你連方向都弄不清楚，最好在
天黑之前趕緊找道路徑出去吧。
LONG
	);
	set("outdoors", "oldpine");

	// Because setup() calls reset(), so we don't need initialize
	// our exits here.
	setup();
}

void reset()
{
	::reset();
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"pine" + (random(5)+2),
///	  "north" : __DIR__"pine" + (random(5)+2),
          "north" : __DIR__"pine5",
	  "west" : __DIR__"pine" + (random(5)+2),
	  "east" : __DIR__"pine" + (random(5)+2),
	]));
}

int valid_leave(object me, string dir)
{
	write("你實在弄不清楚方向....");
	switch(dir) {
		case "north":	write("北邊....北邊是哪裏呢？....");	break;
		case "east":	write("東邊....東邊....");	break;
		case "south":	write("南邊....哪裏是南邊？....");	break;
		case "west":	write("西邊....嗯....");	break;
		default:
			write("該往哪裏走呢....");
	}
	write("就是這個方向吧。\n");
	return 1;
}
