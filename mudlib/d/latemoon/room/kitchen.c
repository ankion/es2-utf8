
inherit ROOM;

void create()
{
   set("short", "廚房");
	set("long", @LONG
你走進廚房，看到有好多的烹飪用品與設備，小蒸籠、大鍋、平  
炊竈、燒飯爐等，五花八門，式樣齊全。旁邊的大倉儲中，更放滿各
式各樣山珍美味，各種材料，調味物品應有盡有。裏頭的掌廚師姐們
忙裏忙外，在爲準備一道道佳餚辛苦著! 聞到那陣陣美味的菜香，你
的肚子咕嚕咕嚕叫了起來!
LONG
	);
    set("exits", ([ 
    "west" :__DIR__"eat2",
    ]));
    set("objects", ([
        __DIR__"npc/obj/fire" : 1,
        __DIR__"npc/fochin" : 1,
    ]) );

	setup();
	replace_program(ROOM);
}
