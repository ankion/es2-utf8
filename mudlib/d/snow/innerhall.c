// Room: /d/snow/innerhall.c

inherit ROOM;

void create()
{
	set("short", "武館內院");
	set("long", @LONG
這裏是淳風武館的內院，平常武館弟子沒有館主的允許是不敢到這
裏來的，往東是柳家的祠堂，館主和家眷的臥房分別位於往北一條走道
的兩旁，廚房以及柴房、僕役的臥房都在往南的走道兩旁，往西則是天
井。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/snow/inneryard",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
