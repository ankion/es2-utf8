// Room: /d/choyin/tongbhill.c

inherit ROOM;

void create()
{
	set("short", "桐柏山");
	set("long", @LONG
鬼神皆修於桐柏,故而此地人煙稀少,僅山下青石峪的那位隱士結廬在此.東邊山
壁天成一洞,據傳是姑射山的仙人煉丹之所,終日烈焰雄雄,烤得此地寸草不生.
然而,一株老鬆仍枝繁葉茂,立於巨石(stone)之上.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northdown" : __DIR__"rockyu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
