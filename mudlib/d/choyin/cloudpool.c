// Room: /d/choyin/cloudpool.c

inherit ROOM;

void create()
{
	set("short", "雲夢大澤");
	set("long", @LONG
雲夢大澤八百里,霧氣沼沼,商旅絕行.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"solidpath2",
]));
        set("objects",([
            "/d/choyin/npc/serpent":4,
                      ]) );
        set("resource/water",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
