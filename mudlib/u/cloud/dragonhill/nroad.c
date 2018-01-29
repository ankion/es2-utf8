// Room: /u/cloud/dragonhill/nroad.c

inherit ROOM;

void create()
{
        set("short", "黃土路");
        set("long", @LONG
這裏是雪亭鎮通往綺雲鎮的必經之路。北面就是雪亭鎮，南面通往
臥龍崗。早先官府想在此修條大路連接兩鎮，無奈地勢所限，加上臥龍
崗上常有強人出沒，只得做罷。雖說是土路，可過往的人很多，路面已
被踩得很平了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/snow/sroad1",
  "southeast" : __DIR__"nhillfoot",
]));
        set("outdoors", "dragonhill");

        setup();
        replace_program(ROOM);
}
