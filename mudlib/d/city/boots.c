// boots.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "李記鞋店");
        set("long", @LONG
這裏是京師中最大的一家鞋店。店主姓李，歷經幾代，已是百
年老店。店鋪挺大，瀰漫着一種特殊皮革的氣味。大櫃檯後面的架
子上放滿了各式的皮靴。店中幾個夥計正在忙碌。
    店門口有一塊金字招牌(sign)。
LONG
        );
        set("exits", ([
                "south"   :  __DIR__"street11" ]) );

        set("objects", ([
              __DIR__"npc/shoer.c" : 1, ]) );

        set("item_desc", ([
                "sign": (: look_sign :),]) );

        setup();

}

string look_sign(object me)
{
        return HIY "專賣各式鞋。\n"NOR;
}

