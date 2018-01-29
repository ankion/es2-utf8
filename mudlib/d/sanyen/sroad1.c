// Room: /d/sanyen/sroad1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
這是一條鋪著生滿青苔大石的山路，但是路面大概常有人行走，因
此倒也並不溼滑，往南是一段石階緩緩下山，往北則是通往山中的山路
，東面的山壁上刻著「山煙寺」幾個大字，看起來歲月已經頗久了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
      "west" : __DIR__"sroad2",
      "northeast" : "/u/cloud/sunhill/road4",
    ]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
