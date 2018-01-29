// Room: /d/oldpine/passage.c

inherit ROOM;

void create()
{
	set("short", "祕密通道入口");
	set("long", @LONG
你現在正站在一個岩石的通道之中，在你南邊有一片亮晶晶的簾幕
(curtain)，從簾幕後面傳來陣陣轟隆隆的水聲，通道兩邊的石壁上安置
著許多銅鑄的燭臺，照亮了這個巖穴，往北似乎有亮光。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "curtain" : "這片簾幕似乎是用一種極薄的絲綢織成的，後面還傳來陣陣水聲。\n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/oldpine/secrectpath1",
  "south" : "/d/oldpine/waterfall",
]));
/*	set("objects", ([ 
  "/d/oldpine/npc/maniac" : 1,
]));
*/
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
