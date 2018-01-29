// Room: /d/snow/sroad3.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
這是一條寬敞堅實的青石板鋪成的大道，路上車馬的痕跡已經在路
面上留下一條條明顯的凹痕，往東是一條較小的街道通往雪亭鎮，大路
從這裏往北可達水煙閣，往西南穿過黃石隘口則通往戍守京畿重地的天
駝關。
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"sroad4",
  "east" : __DIR__"sroad2",
]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
