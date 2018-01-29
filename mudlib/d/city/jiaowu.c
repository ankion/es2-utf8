// Room: /d/city/jiaowu.c
inherit ROOM;
void create()
{
        set("short", "校武場");
        set("long", @LONG
這裏是京師的校武場。一些御林軍正在這裏日夜操練，喊殺聲
此起彼伏。幾個騎着高頭大馬的將領，在場上來回地巡視。每年武
考也是在此舉行的，當年淤蘭天武、蕭避塵、藍芷萍就是在此出盡
了風頭，一時間聲名傳遍長城內外、大江南北。
    北邊是午門，南邊是熱鬧的天橋了。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "south"  :    __DIR__"bridge",
             "north"  :    __DIR__"wumen",]));
/*        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );*/

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

