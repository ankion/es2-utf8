// Room: /d/sanyen/road2.c

inherit ROOM;

void create()
{
	set("short", "石板小徑");
	set("long", @LONG
你正走在一條青石板鋪造的小徑上, 兩旁種植著一排芍藥。陣陣
藥香隨風送了過來, 原來北邊是片廣大的藥圃。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road1",
  "north" : __DIR__"drug_field",
]));
	set("objects", ([
		__DIR__"npc/bonze":1 ]) );
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
