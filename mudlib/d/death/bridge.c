// Room: /d/death/bridge.c

inherit ROOM;

void create()
{
	set("short", "奈何橋");
	set("long", @LONG
你現在正站在一條極長的石橋上，橋頭一塊石碑上面刻著「奈何橋
」三個古篆，東、西兩面都是大霧，連橋底下是不是水都看不到，濃霧
中有許多朦朧的人影魚貫地向北走去，奈何橋往南延伸到一片大霧之中
，北邊引隱約約有一座城樓的影子。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"gate",
		"south" : __DIR__"bridge1",
	]));
	set("objects", ([
		__DIR__"npc/hell_guard": 4,
	]) );

	setup();
	replace_program(ROOM);
}
