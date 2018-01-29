// ROOM:__DIR__"canyon2"

inherit ROOM;
void create()
{
        set("short","隘口小路");
	set("long",@LONG                                   
來到這□，腳下的黃土仍是厚厚的一層，可見得來往這條道路的人必
不多，向北即是隘口尾，往南一直通達天駝關口，兩側依舊是荒冷的山壁
，但似乎更爲嚴峻。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
        	"northeast" : __DIR__"canyon1",
        	"south" : __DIR__"canyon3",
	]) ); //eof(exits)
	
	setup();
	
	replace_program(ROOM);
} //EOF
