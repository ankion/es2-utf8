// bamboo_pipe.c

inherit ITEM;

void create()
{
	set_name("竹管",({ "bamboo pipe", "pipe" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("material", "bamboo");
		set("long", "一根約兩寸多長的竹管，上面戳了三個小孔，也許\可以用來吹奏？\n");
	}
}

void init()
{
	add_action("do_play", ({ "play", "blow" }) );
}

int do_play(string arg)
{
	if( !id(arg) ) return 0;

	message_vision("$N拿起一根" + name() + "嗚嘟嘟地吹了起來。\n",
		this_player() );
	environment(this_player())->pipe_notify();

	return 1;
}
