// Room: /d/oldpine/npath3.c

inherit ROOM;

void create()
{
	set("short", "林間小路");
	set("long", @LONG
你現在正走在一條林間的小路上，小路往東似乎通往一處空地，林
子到了這裏變得靜悄悄的，小路兩旁的松樹也比西邊的矮小，看起來有
點營養不良的樣子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/oldpine/clearing",
  "northwest" : "/d/oldpine/npath2",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
