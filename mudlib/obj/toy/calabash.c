// bottle.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("青葫蘆", ({ "green calabash", "calabash" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "這是一個碧綠色的葫蘆，青裏透黃顏色十分討人喜愛。\n");
		set("unit", "個");
		set("value", 80);
		set("max_liquid", 60);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "甘泉水",
		"remaining": 60,
	]) );
}
