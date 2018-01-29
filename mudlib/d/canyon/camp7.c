// ROOM:__DIR__"camp7"

inherit ROOM;
void create()
{
        set("short","副將營帳");
	set("long",@LONG                                   
來到這□，看了四周的景像真會令人不敢相信，和前面的軍營竟大不
相同，虎皮披于軍椅，銀器列於黑剛曜石桌上，爵爲金緣雙虎抱圖，北側
掛著刀、劍、杖，地面上有羊毛軟皮鋪陳著，確實有副將營帳的味道。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==2 */
		"east" : __DIR__"camp8",
		"west" : __DIR__"camp2",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/vice_general" : 1,
	]) );
	
	setup();
	
}

int valid_leave(object me,string dir)
{
	if ( dir=="east" && !(string)me->query("marks/軍營") )
        return notify_fail("你還沒被允許\進入喔。\n");
	
	return ::valid_leave(me,dir);
}
