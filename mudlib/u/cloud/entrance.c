// Room: /u/cloud/entrance.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "綺雲鎮");
        set("long", @LONG
這裏是綺雲鎮的入口。綺雲鎮是坐落在泓水北岸的一個大鎮, 以其商業
發達和盛產茶葉而爲來往客商們所青睞。北邊過了臥龍崗就是著名的
封山劍派北宗所在的雪亭鎮; 鎮南有個渡口, 過了江就是少林的支脈 
-- 山煙寺。鎮上很是熱鬧, 在這裏就能聽到南邊集市上傳來的叫賣聲。
入口處有個官府的公告(sign), 不知是寫了些什麼。 
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :)
        ]) );

        set("exits", ([ /* sizeof() == 2 */
		  "northwest" : __DIR__"dragonhill/sroad",
		  "south" : __DIR__"nwroad1",
	]));

 //       set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

string look_sign(object me)
{
        return "公告上寫着:[啓事] 由此入鎮收取黃金一兩\n";
}

