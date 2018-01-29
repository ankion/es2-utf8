// Room: /d/waterfog/wpath2.c

inherit ROOM;

void create()
{
	set("short", "山坡小徑");
	set("long", @LONG
你現在正走在一條山坡小徑上，東邊不遠處可以望見水煙閣琉璃色
的屋瓦，小徑東北是一道白石階梯通往山巔的虹臺，往西則是「水煙十
景」之中最有名的虹谷斷崖，小徑旁立著一個七、八尺高的石碑(stone
)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/waterfog/wpath3",
  "east" : "/d/waterfog/wpath1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "石碑上面幾個蒼勁古樸的字寫道：虹谷石臺，乙丑年水煙閣第六代
閣主關雨樓立。
你仔細一看，這幾個字跡絲毫沒有斧鑿痕跡，竟像是題字的人直接
用手指在岩石上寫出來一般。
",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
