// Room: /d/green/station1.c

inherit ROOM;

void create()
{
	set("short", "工作站");
	set("long", @LONG
這裏是採石場的工作站，幾間矮小的房舍延著山壁建造。靠南的山邊
有一間馬房，旁邊還堆著山一般的乾草飼料，幾輛運輸用的車子停在旁邊
。往北看去是採石場的空地往南是一條由石板鋪成的小斜坡，通往村前的
工作站。西邊不遠處有一棟看來相當特別的房舍。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/green/field1",
  "southwest" : "/d/green/station0",
]));
	set("outdoors", "green");
	set("objects", ([
	"/d/green/npc/worker2" :2,
	]) );

	setup();
	replace_program(ROOM);
}
