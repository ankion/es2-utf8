// beef.c

inherit ITEM;

void create()
{
        set_name("雜碎", ({ "fragment" }) );
        set_weight(100);
	set("long", "看樣子是牛或狗的雜碎，但是生的, 好象不能吃。\n");
	set("unit", "堆");
	set("value", 20);
        set("material", "blood");

        setup();
}


	
