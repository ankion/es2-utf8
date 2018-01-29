// Mon  08-21-95

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("陶壺", ({ "pottery" }) );
    set_weight(1000);
    if (clonep())
        set_default_object(__FILE__);
    else {
            set("long","一個手工製造的陶壺, 看起來年代久遠.\n");
            set("unit","個");
            set("value",0);
            set("max_liquid",10);
    }
    set("liquid", ([
        "type" : "alcohol",
        "name" : "米酒",
        "remaining" : 7,
        "drunk_apply" : 7,
    ]) );
}

