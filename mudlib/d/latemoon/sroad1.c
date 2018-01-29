inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
你走在一條蜿蜒的小徑, 小徑的兩旁是半個人高的雜草, 你可以感受
到清涼的微風從兩側吹來。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
         "north: __DIR__"park/moondoor",
         "southeast" :__DIR__"sroad2", 
        ]));
        set("outdoors", "latemoon");

        setup();
        replace_program(ROOM);
}
