// ROOM:__DIR__"blackmarket"

inherit ROOM;

void create()
{
	set("short","兵器庫");
	set("long",@LONG                                   
在這裏你可以看到牆上掛滿了各式各樣的武器，不難明瞭這裏是存放
武器的地方，而牆上寫了個諾大的「武」字。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
		"east" : __DIR__"canyon4",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/seller" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
