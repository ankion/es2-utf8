// Room: /d/oldpine/tree3.c

inherit ROOM;

void create()
{
	set("short", "大松樹頂");
	set("long", @LONG
哇....你終於爬上這株松樹的樹頂了，一陣陣涼風從四面八方吹來
，使你覺得心曠神怡，雖然你的經驗告訴你在這種地方往下看是十分不
智的，但是你還是忍不住看了一眼，這裏離地面至少也有十五、六丈高
，一陣暈眩警告你最好在跌下去以前離開這個地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/oldpine/tree2",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
