// /d/city/shangshu/road4

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long",@LONG
你走在尚書府的一條僻靜的小路上。這條小路連接着花園和一間
廢棄的雜貨屋，平常很少有人來此。東面的花園漸漸地遠了，西面的
門都已經脫落的廢屋已歷歷在目。北面是高聳的院牆。
LONG
        );

        set("exits", ([
		"west":		__DIR__"feiwu",
		"east":		__DIR__"huayuan",
                ]));

	set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

