// ROOM:__DIR__"camp2"

inherit ROOM;
void create()
{
        set("short","營火區");
	set("long",@LONG
地上有些食物的殘渣，而中央地帶則有一營火，在邊邊則有一個水
井，想必是官兵們用來汲水用的，南北兩側爲小隊長的營帳，東方則是
副將軍的營帳，如果沒有事情冒然進入是會被斥責。
LONG
	); // eof(long)
	
	set("resource/water",1);

	set("exits",([ /* sizeof()==4 */
        	"north" : __DIR__"camp5",
        	"south" : __DIR__"camp6",
        	"east" : __DIR__"camp7",
        	"west" : __DIR__"camp1",
	]) ); //eof(exits)

	
	setup();
	
	replace_program(ROOM);
} //EOF
