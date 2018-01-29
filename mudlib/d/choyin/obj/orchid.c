inherit ITEM;

void create()
{
        set_name("寒谷幽蘭", ({ "orchid" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "株");
                set("long", "一株寒谷幽蘭，散發着淡淡的香氣, 你似乎在晚月莊聞到過.\n");
                set("material", "paper");
                set("value", 10000);
        }
        setup();
}

