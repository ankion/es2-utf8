// /d/city/wumen
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "午門");
        set("long", @LONG
這裏是京師的午門。午門進出紫禁城的要道，北面那莊嚴的大門
(gate)後面便是神祕的紫禁城。大門的兩側放着一對石獅(statue)，
虎視眈眈地盯着來往的人羣。南面是歷年選武狀元的校武場，也不知
現在有沒有人。東西向的街道圍繞着紫禁城。
LONG
        );

        set("exits", ([
		"east":		__DIR__"street3",
		"west" :	__DIR__"street4",
		"south" :	__DIR__"jiaowu",
//		"north":	__DIR__"zijincheng",
		]));
        set("outdoors", "city");

//	create_door("north", "鐵門", "south", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

