// Room: /daemon/class/scholar/taolin

inherit ROOM;
/*
#define dir_east	0
#define dir_south	1
#define dir_west	2
#define dir_north	3
#define dir_southeast	4
#define dir_southwest	5
#define dir_northeast	6
#define dir_northwest	7
*/
string Get_Dir(string arg);
int do_read(string arg);
int do_go (string arg);

mapping Note_Msg = ([
        "欲將愁心附明月,隨君直到夜郎--":"dir_west",
        "問君能有幾多愁,恰似一江春水向--流":"dir_east",
        "自笑堂堂漢使,得似洋洋河水,依舊只流--":"dir_east",
        "--朝四百八十寺,多少樓臺煙雨中":"dir_south",
        "孔雀--飛,五里一徘徊":"dir_southeast",
        "簾卷--風,人比黃花叟":"dir_west",
        "醉別--樓醒不記,春夢秋雲,聚散真容易":"dir_west",
        "春草綠色,春水碧波,送君--埔,傷之如何":"dir_south",
        "--望，射天狼":"dir_northwest",
        "--風捲地白草折，胡天八月即飛雪":"dir_north",
        "青山橫--郭，白水繞東城":"dir_north",
        ]);


string	*notemsg;
int 	msg_no;
// int tl_steps;
 
void create()
{
        set("short", "桃林");
        set("long", @LONG
這是很大的一片桃林。每年花開的季節，這裏一片桃花燦爛，總引得
鄰近的鎮集的遊客來觀看，甚至京城的遊客也不乏其人。桃林中阡陌縱橫
，不熟悉此地的遊客經常迷路。當然啦，一些先行者在桃樹枝上掛了些字
條以指示道路。看。。字條（note）在那兒。。
LONG
        );

        set("item_desc", ([
                "note": (: "這是一張指示路徑的字條.似乎可以讀(read)它.\n" :),
        ]) );

        set("exits", ([ 
                "south" : 	__DIR__"taolin",
                "north" : 	__DIR__"taolin",
                "west" : 	__DIR__"taolin",
                "east" : 	__DIR__"taolin",
		"northwest":	__DIR__"taolin",
//		"northeast":	__DIR__"taolin",
		"southeast":	__DIR__"taolin",
//		"southwest":	__DIR__"taolin",
        ]));

	notemsg = keys(Note_Msg);
	msg_no = random(sizeof(Note_Msg));	
//        tl_steps = this_player()->query("taolin_steps");

	setup();
}

void init()
{
	add_action("do_read", "read");
	add_action("do_go", "go");
}

int do_read(string arg)
{
	if (arg != "note") 
		return notify_fail("你要讀什麼?\n");
	    else {
		message_vision("$N看見:"+notemsg[msg_no]+"\n", this_player()); 
		return (1);
		}
}

int do_go(string dir)
{
	int steps;
	object me;

	me = this_player();
	steps = me->query("taolin_steps");
	if (dir == Get_Dir(Note_Msg[notemsg[msg_no]])) {
		if (steps  <= 1) {
			me->delete("taolin_steps");
			message_vision("$N走出了桃林\n",me);
			me->set("marks/桃林", 1);
                        msg_no = random(sizeof(Note_Msg));
			me->move(__DIR__"entrance");
			message("vision",me->name()+"從桃林走了出來。\n",environment(me),({me}));
			return 1;
			}
		    else {
			steps -= 1;  
			me->set("taolin_steps", steps);
			}
		}
	    else {
		steps += 3;
		me->set("taolin_steps", steps);
		}
	
	msg_no = random(sizeof(Note_Msg));
	return 0;
}

string Get_Dir(string arg)
{
	switch (arg) {
		case "dir_east":	return ("east");
		case "dir_south":	return ("south");
		case "dir_west":	return ("west");
		case "dir_north":	return ("north");
		case "dir_southeast":	return ("southeast");
		case "dir_southwest":	return ("southwest");
		case "dir_northeast":	return ("northeast");
		case "dir_northwest":	return ("northwest");
		default:	return ("NULL");
	}

}
