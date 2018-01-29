// Room: /u/cloud/latemoon/entrance.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "碎石小徑");
	set("long", @LONG
這是條用鵝卵石鋪成的小路，往西可以看到一座用淡青色圍牆圍住
的庭院，有兩個身着綵衣的女子笑盈盈的站在那裏說笑着，她們身後的
一扇拱門(door)，檐頂下面寫着「晚月莊」。院牆那邊飄出的陣陣曲聲勾
人魂魄，隱約還可聞到一股香氣。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"gate",
  "east" : "/u/cloud/wroad0",
]));
	set("outdoors", "cloud");

        set("item_desc", ([
                "door": (: look_door, "west" :),
        ]) );

	set("objects", ([
		"/u/cloud/npc/lm_guard": 2 ]) );

	create_door("west", "拱門", "east", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}

/*
void init()
{
	exist_door(ob);
}

void exist_door(object ob)
{
        if( (string)ob->query("gender") == "女性"  )
	        create_door("west", "拱門", "east", DOOR_CLOSED);
}
*/
