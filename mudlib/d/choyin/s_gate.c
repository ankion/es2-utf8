// Room: /d/choyin/s_gate.c

inherit ROOM;

void create()
{
	set("short", "喬陰縣城南門");
	set("long", @LONG
這裏是喬陰縣城的南門，由於這個南門是十多年前重建的，因此和
古老斑駁的東、西、北門相比，南門顯得漂亮許多，而且南門正對著縣
府衙門，平日的修繕當然也勤快些。喬陰縣城南門外住著許多上次羿水
河魯公堤潰決之後遷來的農民，因此雖然出了城門，街道依然人來人往
，往東是一條沿著城牆的街道，可以經過火龍將軍廟入城，西邊的街道
沿著城牆通往新建的驛站，往南則是許多房舍與農田。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"crossroad",
		"east" : __DIR__"dragon_temple",
	        "south" :__DIR__"spath",  
           ]));
	set("objects", ([
		__DIR__"npc/cityguard": 2
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
