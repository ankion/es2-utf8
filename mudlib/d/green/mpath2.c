#include <room.h>

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
這是一段荒蕪的山路，顯然很少有人走過，東面是陡峭的
山壁，山壁上零星的長着幾棵小樹，西面是深不見底的懸崖，
仔細一聽，彷彿下面有潺潺的流水聲。山路的北邊似乎到了
盡頭。
LONG
);
	set("exits",([
	"south":__DIR__"mpath1",
	"north":__DIR__"entrance",
	]) );
	setup();
	replace_program(ROOM);
}

