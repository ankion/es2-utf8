// Room: /d/choyin/rockyu.c

inherit ROOM;

void create()
{
	set("short", "青石峪");
	set("long", @LONG
此地山勢平緩,山坡盡是湘妃竹.南面就是桐柏山了,西面即爲隱士結廬修身之所
.往北可見下山的青石小徑.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"rockpath1",
  "westdown" : __DIR__"fence",
  "southup" : __DIR__"tongbhill",
]));

        set("objects", ([
                    __DIR__"npc/oldman" :1,            
                      ]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
