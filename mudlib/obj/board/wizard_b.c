// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("巫師留言板", ({ "board" }) );
	set("location", "/d/wiz/hall1");
	set("board_id", "wizard_b");
	set("long",
		"這是一個供人留言記事的留言板。\n" );
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
