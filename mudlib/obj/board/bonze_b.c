// bonze_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("緣法輪", ({ "wheel" }) );
	set("location", "/d/sanyen/temple" );
	set("board_id", "bonze_b");
	set("long",
		"這是一個黃銅鑄成的法輪，從它上面斑駁的銅綠痕跡可以看出它的年代已經\n"
		"相當久遠了，緣法輪旁邊放著一本冊子供寺中僧人或香客留言。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
