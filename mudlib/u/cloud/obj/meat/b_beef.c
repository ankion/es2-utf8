// beef.c

inherit ITEM;

void create()
{
        set_name("生牛肉", ({ "beef" }) );
        set_weight(800);
	set("long", "看樣子是牛的後腰，但是生肉, 不知能不能吃。\n");
	set("unit", "掛");
	set("value", 70);
        set("material", "rib");

        setup();
}


	
