#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"絲羅巾" NOR, ({ "hankie" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long",
                        
"這卷羅巾由上等絲綢編成，繡了一幅幅美女圖。個個體態輕盈，翩然\n"
"起舞。每一曲舞步姿態美妙迷人，旁題著舞曲名稱與步法。\n");
                set("value", 100);
                set("material", "silk");
                set("no_drop", 1);
                set("skill", ([
                        "name":                 "move",
                  "exp_required": 5000,
                        "sen_cost":             
30,
                        "difficulty":   20,
                        "max_skill":    50
                ]) );
        }
}
