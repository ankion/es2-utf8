// wizard_j.c

inherit "/std/jboard";

void create()
{
	set_name("巫師工作進度報告", ({ "job board", "board" }) );
	set("location", "/d/wiz/jobroom");
	set("board_id", "wizard_j");
	set("long",	"這是一個特殊的留言板供巫師報告自己的工作進度。\n" );
	setup();
	replace_program("/std/jboard");
}
