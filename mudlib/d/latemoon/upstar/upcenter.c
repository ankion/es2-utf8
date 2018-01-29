
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "佛堂門前");
	set("long", @LONG
這裏是莊院二樓的佛堂門前，你可以聞到一股濃郁的檀香氣息。
走在這裏你有一種莊嚴肅靜的感覺，在閒暇之餘你覺得來到這可以
暫時忘去周遭的煩人瑣事，彷佛可以放開一切� 所有時空都靜止般
的虛空幽靜。西面你看到一扇檀香木門。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"uproom",
    "north" :__DIR__"upstar1",
    "south" :__DIR__"upstar2",

]));

    create_door("west","檀香木門","east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
