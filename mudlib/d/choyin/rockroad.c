inherit ROOM;

void create()
{
        set("short", "礫石路");
        set("long", @LONG
    這是一條鋪著礫石的上路，險峻難行。南面一座高山，雲霧
繚繞險峻異常。山前斷碑字跡依稀可辨--「姑射山』。傳說中有
位仙人曾居於此地，不知如今還在不在......
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/choyin/spath",
  "southup" : "/d/choyin/guyehill",
]));
        set("outdoors", "choyin");
        replace_program(ROOM);
        setup();
}

