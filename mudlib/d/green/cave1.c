#include <room.h>

inherit ROOM;

void create()
{
	set("short","黑暗山洞");
	set("long",@LONG
山洞很矮，幾乎站不直身子，腳下偶爾踩到石頭或是些莫名其妙的東西，
洞內奇寒澈骨，南面是一扇木門，北面隱隱地有些亮光。
LONG
);
	set("exits",([
	"south":__DIR__"cave0",
	"north":__DIR__"cave2",
	]) );
	create_door("south","木門","north",DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

