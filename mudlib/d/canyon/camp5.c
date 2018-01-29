// ROOM:__DIR__"camp5"

inherit ROOM;
void create()
{
        set("short","小隊長營帳");
	set("long",@LONG                                   
這□是小隊長的營帳，四周仍舊和小兵營帳一樣的空曠，但營帳的布
料倒是比小兵營帳好多了，北側有兩把涼椅，看來定是小隊長偷懶時休息
的地方。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"south" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/leader1" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
