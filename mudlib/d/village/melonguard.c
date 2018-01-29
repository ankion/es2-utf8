// Room: /d/village/melonguard.c

inherit ROOM;

void create()
{
	set("short", "瓜棚");
	set("long", @LONG
這是一間茅草鋪頂，竹竿作架的棚子，平時瓜農就在這裏看着瓜地，
他們的警惕性都很高，稍有風吹草動都會警覺起來。瓜地在瓜棚的北面，
往西北走就上了村裏的小路，往南能看到地主田老財的宅院。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"melonfarm",
  "northwest" : __DIR__"road7",
]));
	set("objects",([
		__DIR__"npc/meloner":3,
	]) );
	
	set("no_clean_up", 0);

	setup();
}
