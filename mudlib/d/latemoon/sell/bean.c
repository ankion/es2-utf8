inherit COMBINED_ITEM;

void create()
{
	set_name("仙豆", ({"sen-bean"}));
	set("long",	"這是一粒有點奇怪的豆子，聞了聞有一種上等藥材的味道。\n");
	set("unit", "粒");
	set("base_unit", "粒");
	set("base_weight", 200);
	set_amount(1);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	if( !arg || arg != "sen-bean")  return notify_fail("你要吃甚麼呢? \n");

	message_vision(
	   "$N拿出一粒小丸子，一口給吞了下去。\n"
	   "只見$N臉上泛起一陣紅暈，整個人看起來好多了! \n",this_player()  );
	this_player()->receive_heal("gin", 50);
	this_player()->receive_heal("kee", 100);
	this_player()->receive_heal("sen", 50);

	add_amount(-1);
	return 1;
}
