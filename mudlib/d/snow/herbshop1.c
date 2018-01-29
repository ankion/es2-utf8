// Room: /d/snow/herbshop1.c

inherit ROOM;

void create()
{
	set("short", "藥鋪密室");
	set("long", @LONG
這是一間光線陰暗的密室，從地上厚厚的灰塵看得出來這裏很少有
人出入，靠西邊的地上放著一副腳鐐，連著一條鐵鏈鑲在牆上，不知道
是用來鎖什麼人，南面的牆(wall)是用紅杉木做的，跟另外三面的灰土
牆比起來顯得有些不尋常。
LONG
	);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
