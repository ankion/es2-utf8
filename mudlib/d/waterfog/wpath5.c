// Room: /d/waterfog/wpath5.c

inherit ROOM;

void create()
{
	set("short", "白石階梯");
	set("long", @LONG
你現在走在一道依著山壁而建的白石階梯上，通過西邊不遠處的葬
劍亭，就是虹臺的入口，東邊和北邊都是深不見底的深谷，隔著深谷，
東北邊的野羊山連著隱樵山、圖雲嶺、破魔山、虎嘯坡、沙牢山一直到
大漠都是數百丈的高山，虹臺地勢雖不甚高，但是在三面深谷的環繞下
，卻自有一股羣山朝拜的威嚴氣象。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/waterfog/wpath4",
  "west" : "/d/waterfog/swordtomb",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
