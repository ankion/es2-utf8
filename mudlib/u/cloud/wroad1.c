// Room: /u/cloud/wroad1.c

inherit ROOM;

void create()
{
        set("short", "綺雲鎮街道");
        set("long", @LONG
東邊青板石鋪的路與向西的碎石小徑在這裏匯合。西面彷彿是座莊
院，似可聽到曲樂聲，卻又分辨不清; 南面是傢俬塾。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"bookstore",
  "west" : __DIR__"wroad0",
  "east" : __DIR__"wroad2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

