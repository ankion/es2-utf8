inherit ROOM;

void create()
{
        set("short", "翠綠的小草坪");
        set("long", @LONG
小草坪修剪的很整齊。上面還留着小童玩耍過的痕跡。各種
昆蟲都在這裏建立了它們的樂園。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "east" : __DIR__"home",
          "south" : __DIR__"dustyroad3",
          ]));
          set("objects", ([
           __DIR__"npc/frog" : 2,
           __DIR__"npc/ant"  : 2,
           __DIR__"npc/fly"  : 2,
           ]) );
           set("outdoors", "chuenyu");
           setup();
}
                   