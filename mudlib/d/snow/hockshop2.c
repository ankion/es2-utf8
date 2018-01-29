// Room: /d/snow/hockshop2.c

inherit ROOM;

void create()
{
	set("short", "儲藏室");
	set("long", @LONG
這裏是豐登當鋪的儲藏室，有時候當鋪裏的大朝奉會把鋪裏存不下
的死當貨物拿出來拍賣，不過你現在只能看見一個個鎖著的箱子。往西
邊穿過一道布簾可以回到當鋪店面。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/snow/hockshop",
]));

	setup();
	replace_program(ROOM);
}
