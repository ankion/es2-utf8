// query_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("意見反應留言板", ({ "board" }) );
	set("location", "/d/wiz/entrance");
	set("board_id", "query_b");
	set("long",	"這是一個供人留言記事的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
