// paper_seal.c

inherit COMBINED_ITEM;

void create()
{
        set_name("桃符紙", ({"paper seal", "seal", "paper"}));
        set("long",
                "這是道士們用來畫符的符紙，具有封存法力的功用。\n");
        set("unit", "疊");
        set("base_unit", "張");
        set("base_weight", 5);
        set_amount(1);
}

