// tea_corridor.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("short", "場院");
	set("long", @LONG
    這裏好象是大戶人家子弟玩樂的場院, 原來建有秋千架的草地，
已經成了荊棘叢生的荒草場了。再往西是一座涼亭，亭子似乎也快要倒塌了...
LONG
        );

        set("exits", ([
                "east"          : "/u/cloud/woodboxy",
	        "west"          : "/u/cloud/god2" ]) );

//	set("objects", ([
//	]) );

        create_door("east", "木門", "west", DOOR_CLOSED);

        setup();

}


