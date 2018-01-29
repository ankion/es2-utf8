#include <room.h>

inherit ROOM;

void create()
{
   set("short", "東廂房");
	set("long", @LONG
你進入東廂房來，臨窗的地上鋪著猩紅毛毯，正面設著大紅金錢
蟒靠背，石青金錢蟒引枕，秋香色金錢蟒大條褥。兩邊設一對梅花式
紅漆小几，几上茗琬瓶花俱備。這是一間上等廂房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"eroad1",

]));

      set("objects", ([
          __DIR__"npc/servant" : 1,
          __DIR__"npc/elon" : 1 ]) );
    create_door("west","雕飾房門","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
