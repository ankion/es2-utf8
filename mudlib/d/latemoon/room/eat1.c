
inherit ROOM;

void create()
{
    set("short", "大飯廳");
	set("long", @LONG
你走進一間裝飾華麗的大飯廳，有一種說不出的氣派，一張杉木  
雕飾的大圓桌子在廳子中央，鋪著絲綢彩桌巾，上等南湖紫玉盤，湘
陵的瓷玉碗，銀匙金筷。十分奢華。這是晚月莊宴請賓客的地方，平
常也是莊主及莊內輩份高的前輩用膳的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"eat2",
     "west" :__DIR__"twoc",

]));

    set("objects", ([
        "/d/latemoon/obj/food2" : 1,
        "/d/latemoon/obj/food3" : 2,
    ]));
	setup();
	replace_program(ROOM);
}
