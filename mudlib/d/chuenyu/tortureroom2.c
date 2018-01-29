inherit ROOM;

void create()
{
        set("short", "刑房");
        set("long", @LONG
整間刑房已被乾曷的血跡然成暗紅色。散發着撲鼻的腥臭。牆上掛滿了
各式各樣的邢具。刑房的地上散落着生鏽的鐵鏈和破碎的骷髏。偶爾之間，
你還可以聽到老鼠“吱吱”的尖叫聲。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"tunnel6",
        "east" : __DIR__"tunnel4",
        ]));
        set("objects", ([
         __DIR__"npc/highrat": 2, 
         __DIR__"npc/guard2" : 2
         ]) );
         
         setup();
}
                 