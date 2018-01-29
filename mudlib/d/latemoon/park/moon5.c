inherit ROOM;

void create()
{
   set("short", "桂花園");
	set("long", @LONG
這是一片桂花園，園內種植桂花樹十萬多株，枝幹蒼勁，枝葉  
茂盛，樹冠完整，富有生氣。放眼展望，滿遍披翠蓋綠，蔥鬱的桂
花樹斑爛絢麗，優雅大方，碧海銀花，清香陣陣。薰的遊人醉，衣
發常留餘香。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "south" :__DIR__"moon3",
       "north" :__DIR__"moon2",

]));

    set("objects", ([
        "/d/latemoon/park/npc/flwgirl" : 4 ]) );
	setup();
}
