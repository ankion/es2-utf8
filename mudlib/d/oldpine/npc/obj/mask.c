// mask.c

inherit EQUIP;

void create()
{
	set_name("蒙面頭罩", ({ "mask" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "個");
		set("value", 600);
		set("material", "cloth");
		set("armor_type", "mask");
		set("armor_prop/id", ({"maskman"}) );
		set("armor_prop/name", ({"蒙面人"}) );
		set("armor_prop/short", ({"蒙面人(maskman)"}) );
		set("armor_prop/long", ({
			"這個人頭上戴著蒙面頭罩，八成準備幹什麼壞事。\n"
		}) );
	}
}
