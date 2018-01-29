// Room: /d/temple/ladder5.c

inherit ROOM;

void create()
{
	set("short", "石英岩石階");
	set("long", @LONG
你正站在這階梯的起點, 純白色寬敞的石英岩階梯蜿蜒而上, 在青
翠的山色中形成一條純白色的巨龍。擡頭仰望石階盡頭的那座廟宇, 雖
然無情的歲月已經在它身上留下痕跡, 但仍不失其莊嚴神聖的氣息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"ladder4",
  "westdown" : __DIR__"sroad",
]));
	set("no_clean_up", 0);
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
