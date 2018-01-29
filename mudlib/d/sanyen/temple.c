// Room: /d/sanyen/temple.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "大雄寶殿");
	set("long", @LONG
一陣耀眼的金光向你襲來, 你定神一看原來是座一丈八尺的如來
佛祖金身, 坐在一座三尺高的蓮臺上, 前方的香爐裏香菸緩緩飄上天
。這整座山煙寺都是由上好的檜木搭建而成, 南方則是兩扇敞開的金
門, 價值不菲, 氣勢不凡, 在佛像的右側有道黃布幔, 布幔後似乎是
條通道。西邊則傳來陣陣的流水聲。
LONG
	);
	set("valid_startroom", 1);
    set("exits", ([ /* sizeof() == 3 */
		"south" : "/d/sanyen/road1",
		"west" : "/d/sanyen/inner_yard",
        "north" : "/d/sanyen/corridor",
	]));

	set("objects", ([
		CLASS_D("bonze") + "/master": 1
	]) );

	create_door("south", "金門", "north", DOOR_CLOSED);

	setup();
	call_other("/obj/board/bonze_b", "???");

	replace_program(ROOM);
}
