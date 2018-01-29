// /d/city/shangshu/feiwu

inherit ROOM;

void create()
{
        set("short", "廢屋");
        set("long",@LONG
這是一間已被廢棄的小屋。小屋很陰暗，也很潮溼。就着微弱的光線
，隱約看見小屋裏胡亂地堆放着一些雜物。小屋裏到處掛着蜘蛛網，顯然
很久沒有人來過了。
LONG
        );

        set("exits", ([
		"east":		__DIR__"road4",
                ]));

        setup();
        replace_program(ROOM);
}

