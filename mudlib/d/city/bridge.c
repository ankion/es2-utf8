// Room: /d/city/bridge.c
inherit ROOM;
void create()
{
        set("short", "天橋");
        set("long", @LONG
你來到京師的天橋。這裏熱鬧非凡，人聲鼎沸。雜耍的、賣藝
的、做小買賣的應有盡有。若是仔細尋找，說不定可以買到什麼奇
珍異寶呢。柱子和牆壁上貼滿着花花綠綠的廣告（post）。
    北邊是校武場。再往北就到京師中心……紫禁城了。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "south"  :    __DIR__"street17",
             "west"   :    __DIR__"street12",
             "east"   :    __DIR__"street11",
             "north"  :    __DIR__"jiaowu",]));
        set("objects", ([
               __DIR__"npc/vendor" :1,
               __DIR__"npc/caker"  :1,
	       __DIR__"npc/dumpling_seller":1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

