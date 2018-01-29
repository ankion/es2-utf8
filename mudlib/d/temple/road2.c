// Room: /d/temple/road2.c
#include <room.h>

inherit ROOM;

void create()
{
    seteuid(getuid());
	set("short", "青石小徑");
	set("long", @LONG
繞過了後殿, 出現在眼前的是一棟木造兩層高的屋子。屋子四周
的門窗都緊緊的關著, 門口上方掛著一方藍色琉璃匾額, 上書『藏經
樓』三個金字。門旁立著一個石碑(slab)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "southeast" : "/d/temple/road1",
            "enter" : "/d/temple/book_room1",
]));

        set("item_desc", ([
            "slab" : "石碑上寫著 : \n\n"
                     "    非\n"
                     "    茅  不\n"
                     "    山  得\n"
                     "    弟  進\n"
                     "    子  入\n\n"
           ]) );

    setup();

    reset();
}

void reset()
{
        ::reset();
        set("objects", ([ /* sizeof() == 2 */
            __DIR__"npc/guard_taoist" + (random(3)+1) : 1,
            __DIR__"npc/taoist_guard" + (random(3)+1) : 1,
           ]) );
}

int valid_leave(object me, string dir)
{
     if ( dir=="enter" && (string)this_player()->query("family/family_name") != "茅山派")      
          return notify_fail("\n一道無形的牆擋住了門口, 差點把你的鼻子給撞扁了。\n\n");
     if ( dir=="enter" && (string)this_player()->query("family/family_name") == "茅山派") 
         {
          message_vision("\n$N推開門走了進去, 順手把門關了起來。\n\n", this_player());
          tell_room(__DIR__"book_room1", "你看到門被推了開來, 有人走了進來並隨手把門帶上。\n\n");
          ::valid_leave(me, dir);
         }
     return 1;
}
