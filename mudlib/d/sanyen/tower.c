// Room: /d/sanyen/tower.c

inherit ROOM;

void create()
{
	set("short", "塔林");
	set("long", @LONG
你正站在兩座高塔前, 左邊這一座名曰: 『明心塔』, 右方名叫
『見性塔』。歷來, 當山煙寺中的高僧涅盤後, 遺體火化後所得的舍
利子就存放在這兩座塔裏。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/sanyen/back_temple",
]));

         set("objects", ([
             __DIR__"npc/work_bonze" : 1 ]) );
	set("no_clean_up", 0);
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
