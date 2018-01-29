inherit ROOM;

void create()
{
    set("short", "翠嫣橋");
	set("long", @LONG
這是一座最精美的橋，全長十二米，寬度恰可走兩人。石拱
是單孔結構，青石橋面，漢白玉雕石欄杆，欄板上刻有精緻美麗
的花紋。二十個望柱頭上各有一小孔雀，情態各異，饒有趣味。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "north" :__DIR__"pavilion1",
       "southeast" :__DIR__"paroad1",
       "west" :__DIR__"paroad2",

]));

	setup();
	replace_program(ROOM);
}
