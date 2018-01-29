// northdoor.c
#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "京師北門");
        set("long", @LONG
這是京師的北門，若干年前曾經遭到異族的攻打，因而顯得有
些陳舊。城門正上方清析可見當朝名家書寫的“京師北門”幾個金
字，城牆上貼着幾張告示(sign)。這裏是罪犯逃往北方的必經之地，
官兵們戒備森嚴，動不動就截住行人盤問。一條筆直的青石板大道
向南北兩邊延伸。北邊是郊外，騎馬的、座轎的、走路的，行人匆
匆涌入京師。南邊是城裏，隱約傳來陣陣的喧鬧聲。
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
                "north"            : __DIR__"nroad1",
                "south"          : __DIR__"street16" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3, ]) );  

        create_door("out", "城門", "enter");
        setup();
}

string look_sign(object me)
{
       if( wizardp(me) )
                return "告示上寫著：捉拿靈兒、阿泰。\n";
        else
                return "告示上隱約寫著幾個人名，但都模糊不可分辨了。\n";
}

int valid_leave(object me,string dir)
{
        if ( dir=="out" && 
		( !(string) me->query("marks/京師") 
		&& !(string) me->query("marks/令牌") ) ) {
		tell_object (me, "京師守城兵說道：沒有官府通令，任何人不能出入京師。\n");
                return notify_fail("出城方向的路被京師守城兵擋住了。\n");
		}

	if (me->query("marks/令牌")) {
		::valid_leave(me,dir);
		me->set("marks/令牌", 0);
		return 1;
		}

        return ::valid_leave(me,dir);
}
