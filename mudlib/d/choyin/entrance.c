// Room: /daemon/class/scholar/entrance.c

inherit ROOM;

void create()
{
	set("short", "曼雩臺");
	set("long", @LONG
這裏是雨橋莊西邊的曼雩臺，也是喬陰縣城的文人墨客時常聚集談
論詩文的地方，臺寬約十丈，西邊是連接喬陰縣城的翠柳曲橋，從翠柳
湖中的片片睡蓮中彎彎曲曲地通往西邊的廣場，北邊和南邊各有數十根
樑柱，常有許多落拓的士人將他們的作品貼在這裏希望得到貴人賞識，
往東是一片桃樹林，春天時和翠柳湖畔的柳樹相輝映，蔚爲喬陰縣的第
一盛景。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"west" :	"/d/choyin/bridge5",
		"east" :	__DIR__"taolin",
]));

        set("objects", ([
                CLASS_D("scholar") + "/master":1,
		 ]) );

        set("valid_startroom", 1);

	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me,string dir)
{
        if ( dir=="east" && !(string)me->query("marks/書生") )
		return notify_fail("東行的道路被駱雲舟擋住了.\n");
	if (dir=="east")
        	me->set("taolin_steps", 3);
	return ::valid_leave(me,dir);
}

