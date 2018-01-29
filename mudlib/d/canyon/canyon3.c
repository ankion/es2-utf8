// ROOM:__DIR__"canyon3"

inherit ROOM;
void create()
{
        set("short","隘口小路");
	set("long",@LONG                                   
黃土、黃石還是平鋪於小路上，崎嶇的道路來到這□是比北方平緩多
了，向南二十里就是天駝關口了，東側爲軍營，但軍營四周爲鐵柵所包圍
，想從這□進入軍營內似乎是不太可能。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
        	"north" : __DIR__"canyon2",
        	"south" : __DIR__"canyon4",
	]) ); //eof(exits)
	
	setup();
	
	replace_program(ROOM);
} //EOF
