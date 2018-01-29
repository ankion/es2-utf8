// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "黑松山腰");
        set("long", @LONG
你正在艱難的走在唯一通往山頂的小路上。路邊堆着很多面目
猙獰的巨石。幾棵幼鬆頑強的從石縫中擠了出來。你在這
裏可以看到山頂城堡的大致倫廓。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "down" : __DIR__"base_b_m",
          "up" : __DIR__"high_b_mtn",
          ]));
          set("outdoors", "chuenyu");
          
          setup();
          replace_program(ROOM);
}
                  
