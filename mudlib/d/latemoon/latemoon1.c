#include <room.h>

inherit ROOM;

void create()
{
	set("short","晚月莊大廳");
	set("long", @LONG
走進大廳，擡頭迎面看見的是一面紫紅繡金掛幔，一面屏風將寬敞的
大廳隔成兩半，東西兩面各設著七張紫檀雕案，案上一色白玉羊脂花瓶，
瓶中插著粉紅的處子牡丹，紫檀雕案中間又都掛著七尺來長的畫軸，各式
鳥獸蟲魚，翎毛丹青，栩栩如生，宛如要從畫紙上飛出，嬉戲於大廳之中
，這大廳中的富貴氣派之中透著一股秀氣，但是卻也無一般富豪人家或酒
店的庸脂俗粉之氣。
    屏風兩旁的白石嵌雲柱上工整地刻著一幅對聯寫道：

    「座上珠璣照日月，卻掩珠簾，難爲芳心;
      堂前飄香煥雲霞，不知歲月，但曉清音。」

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" :__DIR__"front_yard",
		"north" :__DIR__"latemoon3",
		"west" :__DIR__"latemoonc",
	]));

	set("objects",([
        __DIR__"npc/servant" : 2,
		CLASS_D("dancer") + "/master" : 1 ]) );
	set("valid_startroom", 1);
	setup();
	call_other("/obj/board/dancer_b", "???");
	replace_program(ROOM);
}
