// ROOM:__DIR__"camp3"

inherit ROOM;
void create()
{
        set("short","小兵營帳");
	set("long",@LONG                                   
這是個由粗略的布料所搭成的小營帳，□面只有三二個小兵，其他的
小兵，大概在另一個小兵營帳□賭博聊天吧，而東邊則是小隊長的營帳。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1*/
		"south" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/guard1" : 2,
	]) );
	
	setup();
	
	replace_program(ROOM);
} //EOF
