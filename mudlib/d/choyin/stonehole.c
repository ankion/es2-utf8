// Room: /d/choyin/stonehole.c

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
石室黑漆漆的,雙目不見物.你的雙手好象觸到了什麼東西(object),懼意頓生.
LONG
	);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
