#include <obj.h>

inherit ROOM;

void create()
{
	set("short", "城隍廟");
	set("long", @LONG
這是一間十分老舊的城隍廟，在你面前的神桌上供奉著一尊紅臉的城
隍，廟雖老舊，但是神案四周已被香火薰成烏黑的顏色，顯示這裏必定相
當受到信徒的敬仰。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"eroad1",
		"west" : __DIR__"square",
	]));
	set("no_fight", "1");
	set("objects", ([ /* sizeof() == 2 */
		"/obj/paper_seal" : 2,
		__DIR__"npc/keeper" : 1,
		__DIR__"obj/denotation" : 1
	]));

	setup();
	replace_program(ROOM);
}
