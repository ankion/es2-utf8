inherit ROOM;

void create()
{
        set("short", "土路");

        set("long", @LONG
這是一條土路，路旁隱約可見房舍，皆已破敗。往南是一座高山，
據說有鬼怪出沒。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"s_gate",
            "south" : __DIR__"rockroad",]));
        set("outdoors", "choyin");

        setup();
        replace_program(ROOM);
}

