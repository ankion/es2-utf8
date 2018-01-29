// Room: /d/sanyen/inner_yard.c

inherit ROOM;

void create()
{
	set("short", "庭園");
	set("long", @LONG
你正站在山煙寺的庭園裏, 這庭園裏不但花草茂盛, 而且小橋流
水, 假山涼亭, 應有盡有, 氣派非凡。北邊有間雅房, 東邊穿過拱門
則是大殿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"heal_room",
		"east" : __DIR__"temple",
	]));
	set("outdoors", "sanyen");

	set("objects", ([
		__DIR__"npc/cripple" :1
	]) );
	setup();
	replace_program(ROOM);
}
