// Room: /u/cloud/eroad1.c

inherit ROOM;

void create()
{
        set("short", "綺雲鎮街道");
        set("long", @LONG
這裏是十字路口的東側，兩邊房子裏都頗爲吵鬧。北面似乎是家春
樓，不時可聽到風塵女子的賣笑聲。南面卻是些三教九流的人物在吆三
喝五，象是家賭場。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/u/cloud/cross",
  "north" : "/u/cloud/jiyuan",
  "south" : "/u/cloud/duchang",
  "east" : "/u/cloud/eroad2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

