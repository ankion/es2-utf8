// old_book_r.c

inherit ITEM;

void create()
{
	set_name("舊書", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"一本民間賴以決定播種、施肥時機的農民曆，對你而言顯然沒有多大用處。\n");
		set("value", 30);
		set("material", "paper");
	}
}
