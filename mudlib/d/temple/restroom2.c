// Room: /u/k/karrimor/temple/restroom2.c

inherit ROOM;

void create()
{
	set("short", "廂房");
	set("long", @LONG
這是一間供香客或其他江湖同道休息掛單的客房, 屋子裏只是簡
單地擺放著幾件傢俱。你聞到天井中傳來淡淡的花香。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
     "west" : __DIR__"corridor3",
]));

    create_door("west","木門","east");
	setup();
}
