// This is a room made by roommaker.

inherit ROOM;

int do_smell(string arg);

void create()
{
	set("short", "神祕洞穴");
	set("long", @LONG
洞內黑漆漆的，幾乎什麼都看不見，只是在一個角落裏
有兩點紅光閃爍，憑你多年的經驗，那一定是一雙野獸的眼
睛。這個地方最好不要久留。
LONG
);
	set("objects", ([
		__DIR__"npc/lion":1,
	]) ) ;

	set("no_magic", 1);
	setup();
}

void init()
{
	add_action ("do_smell", "smell");
}

int do_smell (string arg)
{
	object* list;
	int i;

	if (arg != "grass")
		return notify_fail ("你要用什麼？\n");

	list = all_inventory(this_player());  
	i = sizeof(list);
	while (i--) {
		if (((string)list[i]->query("id")) == "grass")
			message_vision("一陣怪風驟然颳起，$N彷彿騰雲駕霧般。\n", this_player());
			this_player()->move ("/u/cloud/biaoju");
			return 1;
		}

	return notify_fail ("你身上沒有忘憂草啊。\n");
}
