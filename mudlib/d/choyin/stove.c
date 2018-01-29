// Room: /d/choyin/stove.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "丹爐");
	set("long", @LONG
雷霆不斷擊向一粒粒仙丹,仙丹慢慢由黑轉爲紅色.你注意到爐門好象開着.
LONG
	);
         
        tell_room("d/choyin/tongbhill","山洞中噴出一股烈焰, 烤得你覺得自己象個夏威夷烤乳豬......\n"); 
        set("exits",(["out":__DIR__"tongbhill",])); 
        set("no-magic",1);
        set("objects", ([
                __DIR__"obj/tablet" :5,  
                       ]) );     
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
