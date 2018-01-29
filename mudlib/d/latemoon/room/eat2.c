
inherit ROOM;

void create()
{
   set("short", "膳房");
	set("long", @LONG
這是一間膳房，中央擺了二張大圓桌。周圍三十二張雕飾木藤椅。
平常莊內上下用膳的地方，東邊是廚房，西邊則是大飯廳，這雖然不
及飯廳華麗，但所有鍋盤匙碗，也都是上等珍品。有大戶人家的氣派
與富貴。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"kitchen",
     "west" :__DIR__"eat1",

]));

    set("objects", ([
        "/d/latemoon/obj/wine" : 1,
        "/d/latemoon/obj/food" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
