// ROOM:__DIR__"camp1"

inherit ROOM;
void create()
{
        set("short","軍營入口");
	set("long",@LONG                                   
此處爲黃石隘口駐軍的入口，東方爲軍隊飲食的地方，在門口的兩側
有兩位小兵正在值勤。南、北兩側爲小兵的營帳。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==4 */
		"west" : __DIR__"canyon4",
        	"north" : __DIR__"camp3",
        	"south" : __DIR__"camp4",
        	"east" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/door_guard" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
