// /d/city/xiangguo/gate

inherit ROOM;

void create()
{
        set("short", "相國府大門");
        set("long", @LONG
你來到相國府的大門處。雖然相國在朝中也是地位顯赫，但與對
面尚書府比起來，相國的府第顯的寒酸得多。一切都十分簡單，只有
牌匾上的「相國府」還提醒着人們主人的地位。
LONG
        );

        set("exits", ([
                "east":         "/d/city/street4",
                ]));
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

