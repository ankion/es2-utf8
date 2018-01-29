inherit ROOM;

void create()
{
    set("short", "沁芳亭");
	set("long", @LONG
亭子座落在園內小水池上，亭柱周圍以弧形座凳式欄板，內外
雕刻各種不同樣式的梅枝，鑽尖式紫琉璃瓦頂，天花板也有雕刻非
常精細的百花圖案。上下擔額枋彩畫題材是海墁式點金加彩瓊花。
體形別緻，色彩豐富。亭邊石橋飛架，通萃賞樓，輕靈精巧，爲園
中一大奇景。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "north" :__DIR__"bridge1",
       "south" :__DIR__"bridge2",

]));

    set("objects", ([
        __DIR__"npc/shiren" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
