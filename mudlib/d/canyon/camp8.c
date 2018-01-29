// ROOM:__DIR__"camp8"

inherit ROOM;
void create()
{
        set("short","將軍營帳");
	set("long",@LONG                                   
虎頭掛於營頂，虎皮披於帳上，威武無比，帳中龍柱頂天，雙龍吐珠
圖掛於前，嚴然有天子之勢，金椅銀桌，□、簋、爵、角、鑑，樣樣俱全
，一磬、一鼓、一笙、一笛、一蕭，文墨章筆擎於旁，將軍在上，參謀在
右，由不得令人生畏。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
        	"west" : __DIR__"camp7",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/general" : 1,
		__DIR__"npc/adviser" : 1,
	]) );
	
	setup();
	
//	replace_program(ROOM);
} //EOF
