inherit ITEM;

void create()
{
    set_name("信件", ({ "letter" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	    set("unit", "封");
	    set("long",@LONG
師叔：
    小徒在我這裏學滿，欲求教於您老，敬請收納他爲徒。
                                侄：劍秋 敬上
LONG
);
            set("material", "paper");
            set("value", 100);
        }
        setup();
}


