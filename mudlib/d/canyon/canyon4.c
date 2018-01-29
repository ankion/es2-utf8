// ROOM:__DIR__"canyon4"

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","隘口中道");
	set("long",@LONG                                   
來到這□，風勢比其他地方大了許多，或許是因爲東邊爲軍營入口通
風較爲良好的原因，南方一十里路的地方就是京城關口－天駝關的入口，
在西邊的山壁似乎過於平滑，不太自然，或許這□有什麼祕密也說不定。
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==3 */
        	"north" : __DIR__"canyon3",
        	"south" : __DIR__"canyon5",
        	"east" : __DIR__"camp1",
	]) ); //eof(exits)
	
	setup();
	
} //EOF

void init()
{
	add_action("do_swear","swear");
} //eof(init)

int do_swear(string arg)
{
	object me;

	me=this_player();
	
	if (!this_player()->query_temp("軍營/swear") ) return 0;
	
	if (!arg) return notify_fail("天空突然一聲轟響:不要吵～～～\n");
	
	if (arg != "我愛安尼席洛特爾" && arg != "我愛東方故事II")
		return notify_fail("天空突然一聲轟響:不要吵～～～\n");
		
	this_player()->set_temp("軍營/swear", 0);
	
    	message_vision(HIB"突然間一陣強光將"HIW"$N"HIB"給罩住了\n"NOR,me);
    	message_vision(HIW"轟隆～～～～～～～～～～～～～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～轟隆～～～～～轟隆～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～轟隆～～～～～～～～轟隆～\n"NOR,me);
    	message_vision(HIC"$N"HIW"慘叫了一聲:哇，好痛啊～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～～～～～～～～～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～～～～～～～～～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～～～～～～～～～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～～～～～～～～～～～～～～\n"NOR,me);
    	message_vision(HIW"～～～～～～～～～～～～～～～～～～～～\n"NOR,me);
    
    	tell_room(__DIR__"blackmarket",me->name()+"被傳送過來了。\n");
    	tell_room(environment(me),me->name()+"突然間消失了\n",me);
    	this_player()->move(__DIR__"blackmarket");
    	return 1;

} // EOF

