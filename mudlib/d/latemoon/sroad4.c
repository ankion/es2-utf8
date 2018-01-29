inherit ROOM;

void create()
{
	set("short", "蜿蜒小徑");
	set("long", @LONG
這條蜿蜒的小徑通往西南方, 西邊是一片茂密的竹林, 小
徑兩旁是綠油油的草地，涼風從草地上吹拂而過，像嬉戲的兒
童般溜過你的足畔，使你不知不覺間腳步輕快了起來。
LONG
	);
	set("exits", ([
		"west" :__DIR__"sroad3",
		"south" :__DIR__"sroad5",
	]));

	set("objects", ([
	   "/d/latemoon/npc/butterfly" : 1 ]) );
	set("outdoors", "lateroom");
	setup();
	replace_program(ROOM);
}
