// Room: /d/city/street7.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
京師的中軸線和北面的主要街道護國道在這裏交叉，東西向的護
國道上人來人往，熱鬧非凡，南面的皇家祭壇反倒冷冷清清，往北可
以望到大紅顏色的北城門。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"street8",
  "west" : __DIR__"street15",
  "north" : __DIR__"street16",
  "south" : __DIR__"jitan",]));

	set("outdoors", "city");

	setup();
	replace_program(ROOM);
}
