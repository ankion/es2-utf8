// tearoom.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
        set("short", "香茗坊");
        set("long", @LONG
你來到綺雲鎮西邊的一家茶坊裏, 它的歷史已不下百年, 綺雲鎮本 
就是以盛產茶葉而聞名於世, 因此茶樓的生意出奇的好。
    高高懸起的金匾(sign)讓你的有一種眩暈的感覺, 幸好陣陣茶香使
你清醒了許多。
    站在門口, 你可以看到北首有一扇不太起眼的木雕門(door)。
    東側的樓梯通往樓上的雅座, 不時能聽到上面傳來絲竹之聲和陣陣
笑聲... 
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :),
                "door": (: look_door, "north" :),
        ]) );

        set("exits", ([
                "south"          : "/u/cloud/nwroad3",
                "west"           : "/u/cloud/nwroad1",
                "north"          : "/u/cloud/tea_corridor",
                "up"             : "/u/cloud/tearoom2" ]) );

        set("objects", ([
                "/u/cloud/npc/tea_waiter" : 1,
 ]) );

        create_door("north", "木雕門", "south", DOOR_CLOSED);
       set("valid_startroom", 1);

        setup();

        "/u/cloud/board/common_b"->foo();
}

string look_sign()
{
        return "匾上寫着: 香茗坊 ， 旁邊一排小字: 御賜親筆。 \n";
}


