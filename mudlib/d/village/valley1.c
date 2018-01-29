// Room: /d/village/valley1.c

inherit ROOM;

void create()
{
	set("short", "忘情谷外");
	set("long", @LONG
這裏是忘情谷外的一條小路，向着南和北延伸。山嶺上樹木繁茂，綠
草茵茵，東面是有名的玉螺湖，湖上水汽蒸騰，但這邊岸上沒有船，不能
由此到湖上。隱隱約約地看的見錯落有致的村莊農舍。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"valley2",
  "eastdown" : __DIR__"lakebottom2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
