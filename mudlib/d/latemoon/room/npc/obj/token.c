// token.c

inherit ITEM;

void create()
{
	set_name("殺手令牌", ({ "token", "###token###" }));
	set_weight(200);
	set_max_encumbrance(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "個");
		set("long", "一個黑木作的殺手令牌，上面刻著火焰的圖騰標誌。\n");
		set("value", 1200);
		set("material", "wood");
	}
}
