
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("火摺", ({ "fire" }) );
    set("unit", "個");
    set("long","這是一個可以生火的火摺");
    set_weight(50);
    setup();
}
