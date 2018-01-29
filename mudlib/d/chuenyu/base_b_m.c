// Room: /d/chuenyu/base_b_mtn.c
inherit ROOM;

void create()
{
        set("short", "黑松山腳");
        set("long", @LONG
一座高而險的山峯聳立在你面前。北面是一條上山的羊腸小路，盤旋曲折。
黑湮湮的松林給你不祥的感覺。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"sunnyroad",
          "up" : __DIR__"foot_b_mtn",
]));
        set("outdoors", "chuenyu");
        
        setup();
        replace_program(ROOM);
}
                          