#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "夾道");
        set("long", @LONG
你現在處於一個窄窄的夾道里，通向北面的路被一塊巨石(rock)堵死。
夾道的兩側是三丈高的石牆(wall)。出乎你的意料，石牆上佈滿了
碗大的圓孔(hole)。石牆的後面傳出“吱吱嘎嘎”的聲音(noise)。
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"gate_castle",
        ]));
        set("item_desc", ([
        "wall" : "這是一道三丈高，厚達尺許的石牆。牆上的圓孔很適合用來發暗箭。\n",
        "rock" : "這是一塊千斤巨石，阻住了通向北面的路。\n",
        "hole" : "你試着往圓孔裏看，可是裏面太黑了，什麼也看不到。\n",
        "noise": "這顯然是拉開強弩的聲音。\n"
]));

        set("outdoors", "chuenyu");
        
        create_door("south", "城門", "north", DOOR_CLOSED);
        setup();
}

void init()
{       object ob;
        if( interactive( ob = this_player()))
        remove_call_out("arrowing");
        call_out("arrowing", 15, ob);
}

int arrowing(object ob)

{
        int i;
        int damage;
        if( environment(ob) == this_object())
        {
        message_vision(HIW"剎那間石牆的後面“嘣嘣”聲不絕，無數羽箭從圓孔中向$N激射而出！！\n", ob);
        message_vision("$N被亂箭射得頭破血流，遍體鱗傷！\n"NOR, ob);
        i = (int)ob->query("eff_kee");
        damage = random(10)+35  ;
        ob->set("eff_kee",(int) i - damage );
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
        if( environment(ob) == this_object())
        call_out("arrowing",5, ob);
        }
        else
        
        return 1;
}
                                        