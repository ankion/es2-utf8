// Room: /d/village/road4.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
青石小路兩旁沒有樹木，幾根雜草隨風搖擺，路上的石頭被行人踩磨得
很光亮，但奇怪的是平時這裏的行人卻非常稀少！小路向西延伸開去，南面
是一片大大的瓜地，北面是一家農舍。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"farmhouse1",
  "west" : __DIR__"road5",
  "southdown" : __DIR__"melonfarm",
  "east" : __DIR__"road3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
