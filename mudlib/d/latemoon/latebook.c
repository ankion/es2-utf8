
inherit ROOM;

void create()
{
      set("short","後院書房");
	set("long", @LONG
這是一間小小的書房，窗明几淨，樸素典雅，一張古意盎然的紅木書桌，
吸引了你的目光，上面擺著一座小小的香爐，幾本善本書整齊的堆放在桌上
，可見主人相當的愛惜書本。一幅「滄海龍吟」的舞曲圖畫掛在牆上，似乎
有一些祕密在裏頭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"latemoon7",

        ]) );
        set("item_desc", ([
                "dragon-dance" : @TEXT
這是一幅湘繡的彩圖，上有幾名貌美的女子，以不同的姿態
舞著，其漫妙之處讓你著迷。圖旁另繡有一曲名『西出陽關』
(dancing out)與『有鳳來儀 』
TEXT
]));

      set("objects", ([
          __DIR__"npc/girl" : 1 ]) );
	setup();
	replace_program(ROOM);
}
