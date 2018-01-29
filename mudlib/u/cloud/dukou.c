// Room: /u/cloud/dukou.c

inherit ROOM;

void create()
{
        set("short", "江北渡口");
        set("long", @LONG
這是個雖說不大卻過客甚多的渡口。往北去是通往綺雲鎮裏的青石
道，南面就是無風亦起浪的泓水了。向南望去，隱約可見對岸日照山的
輪廓，山頂有裊裊炊煙升起。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad1",
  "south" : __DIR__"sunhill/northriver",
]));

	set("objects", ([
                "/u/cloud/npc/boater" : 1,
	]) );

        set("outdoors", "cloud");

        setup();
}
