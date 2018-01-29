// Room: /d/city/street9.c
inherit ROOM;
void create()
{
        set("short", "京師街道");
        set("long", @LONG
你現在正走在京師的大街上。東邊就是京師的東一門了，隱約
傳來官兵搜查行人的吆喝聲。在你的北邊是京城的武器店，據說江
湖上半數以上的武器精品出於此店。從店中走出的人都是一副心滿
意足的模樣。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "east"  :    __DIR__"eastdoor1",
             "north" :    __DIR__"weapon",
             "west"  :    __DIR__"street8",]));
        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}
