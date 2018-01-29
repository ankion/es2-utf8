// Room: /d/snow/sroad2.c

inherit ROOM;

void create()
{
	set("short", "雪亭鎮街道");
	set("long", @LONG
這裏是雪亭鎮的街道，你的北邊有一家客棧，從這裏就可以聽到客
棧里人們飲酒談笑的聲音，街道往東不遠處有個轉角往北，如果你往東
直走就是上山的小徑了，往西則可以走到車馬來往絡繹不絕的官道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"sroad3",
  "south" : __DIR__"school",
  "east" : __DIR__"sroad1",
  ]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/farmer" : 2,
  ]));
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
