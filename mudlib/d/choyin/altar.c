// Room: /d/choyin/altar.c

inherit ROOM;

void create()
{
	set("short", "火龍將軍廟");
	set("long", @LONG
這裏就是奉祀火龍將軍的大殿，火龍將軍高大威武的神像(statue)
就立在你的面前，旁邊還有火龍將軍的部屬虎豹熊鷹四位將軍，你現在
所站的地方是橫過街道而建的一個高臺，隔著欄杆可以看見下面的街道
川流不息的人羣，南北各有一道階梯往下回到街道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"dragon_temple",
]));
	set("no_fight", "1");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"obj/denotation" : 1,
		__DIR__"npc/lady" : 1,
]));
	set("no_clean_up", 0);
	set("no_magic", "1");
	set("valid_startroom", "1");

	setup();
	replace_program(ROOM);
}
