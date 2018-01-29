// Room: /d/green/house3.c

inherit ROOM;

int num_of_spider;

string call_spider();

void create()
{
	set("short", "民宅");
	set("long", @LONG
這是一間民宅, 屋內除了一張石牀外其他一無所有. 昏暗的屋
內看來死氣沉沉的, 似乎這屋子的主人很久沒回來了. 屋角有一個
形狀很奇怪的蜘蛛網(web).
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/green/field1",
]));
	set("no_clean_up", 0);
	set("item_desc", ([
	"web" : (: call_spider :),
	]) );

	setup();
	reset();
}

void reset()
{
	::reset();
	num_of_spider = 3;
}

string call_spider()
{
	object ob;
	if (num_of_spider == 0) return "一個很大的蜘蛛網.\n";
	num_of_spider --;
	ob = new("/d/green/npc/spider");
	ob->move("/d/green/house3");
	return "突然你覺得頭上有個陰影, 不自覺的擡起頭來一看 ............"+
	"好大的 ..... 蜘蛛..... \n";
}
