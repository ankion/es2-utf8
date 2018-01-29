// Room: /d/choyin/w_street1.c

inherit ROOM;

int do_lift (string arg);
int do_check ();

void create()
{
        set("short", "西大街");
        set("long", @LONG
這裏是喬陰縣城的西大街，西邊就是縣城的西門，一座巨大的牌樓
上刻著「西門」二字，往北有一條小巷，南邊則是一間書肆，街道中央
立著一尊石獅(statue)，而且是站著的，將來往行人分爲左右兩道。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "statue" : 
"這尊石獅跟一般尋常人家放在門口鎮宅避邪的石獅頗有不同，姿勢是立
著的，而且大小要大得多，只怕有幾萬斤重，從來沒見過誰能舉起它。
你注意到石獅的額頭上刻著一個「□」字，不知是何用意？
",
]));
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"w_street2",
]));
        set("no_clean_up", 0);
        set("outdoors", "choyin");

        setup();
}

void init()
{
        add_action ("do_lift", "lift");
	add_action ("do_check", "check");
}

void do_check()
{
	printf("%s\n", query("liftid"));
}

void check_trigger()
{
	object me ;
	me = this_player();

        if  ((int) query("lift_trigger") + me->query("str")/5 >= 10) {
                message("vision", "石獅子竟然向左移動了尺許，漏出向下的洞穴。\n"+
"$N從洞口掉了下去。\n",environment(me),({ me }) );
		me->move(__DIR__"lionroom");
                message_vision ("$N石獅子又緩緩地向右移動了尺許，正好蓋住洞口。\n", me);
		set("liftid", me->query("id"));
                }
}

int do_lift (string arg)
{
	string id ;
	object ob;

        if (arg != "statue")
                return notify_fail("你要推什麼？\n");

        message_vision ("$N努力地擡着石獅子，試圖擡起一點點。\n", this_player())
;
	id = (string) query("liftid");
/*	if ( id && ( id != (string)this_player()->query("id")) ) 
		return 1 ;
*/
	if ( id ) {
		ob = find_player(id);
		if ( ob && (environment(ob)->query("short") == "神祕洞穴"))
		return 1;
		}

 	if ( !id ) set("liftid",(string)this_player()->query("id"));

        add("lift_trigger", 1);
        check_trigger();
        return 1;
}

/*int valid_leave(object me,string dir)
{
	if ( ::valid_leave(me,dir) ) {
		delete("liftid");
		delete("lift_trigger");
	}
	return 1;
}
*/
void reset()
{
        delete("lift_trigger");
	delete("liftid");
        ::reset();
}

