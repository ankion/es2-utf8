// phantomforce.c

inherit ITEM;

void create()
{
//	seteuid(geteuid());

	set_name("一具已經腐朽的骸骨", ({ "skeleton" }));
	set_weight(3500);
	set("unit", "具");
	set("long",
		"一具已經腐朽的骸骨靜靜地不知躺了多久。\n"
	);
	set("no_get", "不能丟棄");
}
