// Room: /u/sunhill/midriver.c

inherit ROOM;

void create()
{
        set("short", "江心");
        set("long", @LONG
這裏雖說是泓水最窄的地方，可泓水在這裏轉了個彎，所以常有暗
流出現。常有過往船隻在這裏沉入江底，連水性了得的船伕們也不敢在
風大浪急時過江。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"northriver",
  "south" : __DIR__"southriver",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

