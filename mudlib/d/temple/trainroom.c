// Room: /u/k/karrimor/temple/trainroom.c

inherit ROOM;

void create()
{
    set("short", "練功\房");
	set("long", @LONG
你正站在一間寬闊的大房間裏, 這裏是茅山派弟子打坐練功的地
方, 空氣中瀰漫著一股股汗臭味。四周的牆壁上畫著一幅幅經脈穴道
圖。靠近牆壁的地上則擺著一個個練功用的木人。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
     "south" : __DIR__"corridor4",
]));

     set("objects", ([ /* sizeof() == 1 */
     __DIR__"npc/taoist" : 1,
     __DIR__"npc/taoist2" : 1,
     ]) );

    create_door("south", "木門", "north");
	setup();
}
