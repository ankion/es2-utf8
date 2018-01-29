// Room: /d/snow/secrect_storage.c

inherit ROOM;

void create()
{
	set("short", "地下密室");
	set("long", @LONG
這裏是一間窄小的密室，你的面前只有一個破舊的小牀(bed)跟一
些乾草。
LONG
	);

	setup();
	replace_program(ROOM);
}
