// Room: /d/city/street16.c

inherit ROOM;

void create()
{
	set("short", "大柵欄");
	set("long", @LONG
從這裏再往北走就出了京師的北城門，在與異族交戰的時期，爲
方便盤查行人，官兵在這兒放了一道很大的柵欄。後來儘管戰爭結束
了，柵欄拿走了，但老人們還是習慣地把這叫做“大柵欄”，用京音
讀起來就變成了“大世爛兒”。西面是護國寺的側門。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//  "west" : "d/city/siyuan",
  "north" : __DIR__"northdoor",
  "south" : __DIR__"street7",]));
	set("outdoors", "city");

	setup();
	replace_program(ROOM);
}
