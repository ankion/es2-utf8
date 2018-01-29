// dancer_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("沐花鏡屏", ({ "mirror" }) );
	set("board_id", "dancer_b");
	set("location", "/u/cloud/latemoon/hall" );
	set("long",@LONG
    這是一面有一個人高的鏡屏，有著古藤纏繞著的紅木鏡框，上面還
綴著一些剛採來的鮮花，你看著鏡中的自己，有如站在花叢之中，晚月
莊的女子喜歡將自己的心事寫成紙條綁在鏡框上。
LONG
	);
        setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
