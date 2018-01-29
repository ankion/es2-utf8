// Room: /d/choyin/sw_road1.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
這是一條沿著湖岸的街道，往東北可以通到人車來往的南門廣場，
這一帶原本是在喬陰縣城的舊南門之外，因此仍然保留濃厚的鄉村氣息
，往南是一條小路繼續沿著湖岸通往翠柳湖南岸，街道往東通往著名的
火龍將軍廟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"s_street1",
		"west" : __DIR__"dragon_temple",
]));
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
