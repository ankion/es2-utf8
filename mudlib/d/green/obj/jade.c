inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("玉佩", ({ "jade" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long",@LONG
上面刻著一些字:
行氣, 深則蓄, 蓄則伸, 伸則下, 下則定, 定則固, 固則萌, 萌則長, 長則退,
退則天. 天幾舂在上, 地幾舂在下, 順則生, 逆則死.
LONG
        );
                set("value", 1000);
                set("material", "jade");
                set("skill", ([
                        "name":                 "force",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 25,
                        "max_skill":    40
                ]) );
        }
}
