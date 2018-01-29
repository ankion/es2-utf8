// Room: /d/choyin/court1.c

inherit ROOM;

void create()
{
	set("short", "縣府衙門");
	set("long", @LONG
這裏是喬陰縣府衙門的大門，就像你印象中的衙門一般，高大的大
門、兩隻巨大的石獅、以及一種令人爲之肅然的氣氛。門口有一面大皮
鼓(drum)，不用說，這當然是讓百姓擊鼓申冤用的，喬陰縣的知縣據說
是槐陽王的侄子，雖然算不上是包青天，不過倒也沒有聽說過有什麼貪
贓枉法的劣跡。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"crossroad",
	]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");
	set("objects", ([
		__DIR__"npc/judge_gu.c" : 4,
                __DIR__"npc/magistra.c" : 2
	]) );

	setup();
	replace_program(ROOM);
}
