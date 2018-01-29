// Room: /d/snow/mstreet2.c

inherit ROOM;

void create()
{
	set("short", "雪亭鎮街道");
	set("long", @LONG
你現在正走在雪亭鎮的大街，往南直走不遠處是鎮上的廣場，在你
的東邊是一間大宅院，不過正門不在這個方向，往西是一家打鐵鋪子，
叮叮噹噹的聲音大老遠可以聽得到，街道往北邊一直通往鎮外。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/snow/mstreet3",
  "south" : "/d/snow/mstreet1",
  "west" : "/d/snow/smithy",
  "east" : "/d/snow/workplace",]));
	set("objects", ([
	__DIR__"npc/drunk" : 1,
		__DIR__"npc/scavenger": 1 ]) );

	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
