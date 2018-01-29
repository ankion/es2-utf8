// Room: /d/city/street3.c

inherit ROOM;

void do_climb (string arg);

void create()
{
        set("short", "京師東街");
        set("long", @LONG
這是京師東街的南段。整個東街都被掌管天下兵馬印的尚書府佔
據了，東邊便是尚書府的大門，南邊則是尚書府高聳的圍牆(wall)，
北去的道路一直通向振遠總局。
LONG
        );
        set("exits", ([ 
		"east":		__DIR__"shangshu/gate",
		"west":		__DIR__"wumen",
		"north":	__DIR__"street2",
		]));

	set("item_desc", ([
		"wall": (: "一段高高的院牆，但對輕功好的人爬上(climb)似非難事。\n" :),
		]) );

        set("outdoors", "city");

        setup();
}

void init ()
{
	add_action ("do_climb", "climb");
}

void do_climb (string arg)
{
	if ((arg == "wall") || (arg == "up") || (arg == "牆")) 
		this_player()->move(__DIR__"wall");
}
	
