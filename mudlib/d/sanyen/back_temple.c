// Room: /d/sanyen/back_temple.c

inherit ROOM;

void create()
{
	set("short", "後殿");
	set("long", @LONG
一間寬大的後殿, 正中有一尊藥師如來的金身塑像。四周的牆上
唯妙唯肖地彩繪著十八羅漢, 每個羅漢的旁邊並寫著他得道昇天的過
程。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/sanyen/corridor",
  "east" : "/d/sanyen/tower",
]));

     set("objects", ([
         __DIR__"npc/little_bonze" : 1 ]) );

	setup();
	replace_program(ROOM);
}
