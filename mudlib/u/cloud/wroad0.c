// Room: /u/cloud/wroad0.c

inherit ROOM;

void create()
{
        set("short", "綺雲鎮街道");
        set("long", @LONG
東邊青板石鋪的路與向西的碎石小徑在這裏匯合。西面彷彿是座莊
院，似可聽到曲樂聲，卻又分辨不清; 北面是紅娘莊，常常有一對對
男女來往。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/latemoon/entrance",
  "east" : __DIR__"wroad1",
  "north" : __DIR__"marry_room",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

