// Room: /d/city/street13.c
inherit ROOM;
void create()
{
        set("short", "京師街道");
        set("long", @LONG
你來到京師的大街上。西邊是京師的西二門，西去的人不時經
過這裏。南邊是京師的監獄，關押着一些重要的犯人。站在這裏可
以清楚地聽到獄卒拷打犯人的皮鞭聲和犯人的慘叫聲。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "west"   :    __DIR__"westdoor2",
             "east"   :    __DIR__"street12",]));
//             "south"  :    __DIR__"jial",]));
        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}
