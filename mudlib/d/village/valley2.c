// Room: /d/village/valley2.c

inherit ROOM;

void create()
{
	set("short", "忘情谷外");
	set("long", @LONG
這裏是忘情谷外的一條小路，往東就進了名叫傅家坡的小村莊。從村
莊往外的這段小路人煙稀少，但能經常見到有大鳥飛過忘情谷的山嶺。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"valley1",
  "east" : __DIR__"road6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
