#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "沐浴更衣室");
	set("long", @LONG
這是一間更衣室，你看到許多櫃子，衣架上掛了許多的衣服飾
品。牆上的架上掛了一些絲巾，你可以聞到淡淡的香氣圍繞四周。
東側一藍青灑花軟簾，隔簾望去，隱約可看到小花池，一團的霧氣
你有點想去沖涼沐浴，讓精神好些。當然此處是禁止男性進入!
LONG
	);
    set("no_fight", 1);
    set("objects", ([
       __DIR__"npc/shinyu" : 1,
    ]) );

      set("exits", ([ 
        "west" :__DIR__"flower1",
        "east" :__DIR__"bathroom",
      ]));

    create_door("west","小簾門","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if( (string)me->query("gender") != "女性" ) {
        me->apply_condition("rose_poison", 5);
        tell_object(me, HIG "你覺得有人向你身上灑下一些粉末！\n" NOR );
        }
        return 1;
}
