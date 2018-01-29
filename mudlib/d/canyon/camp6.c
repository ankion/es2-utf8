// ROOM:__DIR__"camp6"

inherit ROOM;
void create()
{
        set("short","小隊長營帳");
	set("long",@LONG                                   
類似北邊的營帳，空空蕩蕩的，看起來一點也不像是軍營，一點威武
的感覺也沒有，在這也有兩把簡易的涼椅，兩位隊長，平常小兵沒有尢許
是不能擅自進入這□的，向東北是副將營帳，但沒有經過「允許」是不得
進入的。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
        	"north" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/captain" : 1,
		__DIR__"npc/leader2" : 1,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
