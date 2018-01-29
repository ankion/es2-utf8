// ROOM:__DIR__"camp4"

inherit ROOM;
void create()
{
        set("short","小兵營帳");
	set("long",@LONG                                   
這□有一大羣的小兵，不知道是在做什麼，營帳中央有一張桌子，上
面堆滿了各式各樣的賭具，小板凳，和茶水。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/guard1" : 2,
		__DIR__"npc/guard2" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
