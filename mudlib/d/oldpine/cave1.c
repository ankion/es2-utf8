// Room: /d/oldpine/cave1.c

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
你現在已經到達山洞的深處了, 四面八方都是些黑漆漆的小石洞,
簡直不知道該往那裏走, 要不是北面還有一點光線, 你都要徹底絕望了。
LONG
	);

	setup();
}

void reset()
{
        ::reset();
        
	set("exits", ([ /* sizeof() == 4 */
        	"south" : __DIR__"cave" + (random(4)+1),
          	"north" : __DIR__"cave2",
          	"west" : __DIR__"cave" + (random(3)+1),
          	"east" : __DIR__"cave" + (random(4)+1),
        ]));
}

