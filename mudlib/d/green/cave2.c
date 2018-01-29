#include <room.h>

inherit ROOM;

void create()
{
	set("short","黑暗山洞");
	set("long",@LONG
山洞很矮，幾乎站不直身子，腳下偶爾踩到石頭或是些莫名其妙的東西，
洞內奇寒澈骨，南面似乎可以前行，北面是一出口。
LONG
);
	set("exits",([
	"south":__DIR__"cave1",
	"north":__DIR__"mpath0",
	]) );
	setup();
	replace_program(ROOM);
}

