// Room: /d/chuenyu/dungeon.c

inherit ROOM;

void create()
{
        set("short", "刑房");
        set("long", @LONG
你處在一個陰溼的地牢裏。地牢的角落裏堆着一些乾草，乾草上沾滿了
暗紅色的血跡。許多骷髏被生鏽的鐵鏈綁在牆上。偶爾之間，你還可以聽到
老鼠“吱吱”的尖叫聲。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"tunnel3",
          "north"   : __DIR__"tunnel4",
]));

        set("objects", ([
                __DIR__"npc/chuenyu" : 1,
                __DIR__"xiaojuan2" : 1,
        ]) );
                
                
        setup();
}
 
                                  