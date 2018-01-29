// Room: /d/wiz/jobroom.c

inherit ROOM;

void create()
{
	set("short", "工作進度簡報室");
	set("long", @LONG
這裏是巫師們報告自己工作進度的簡報室，同時也是大巫師抓公差
的根據，如果你有工作做，最好常常到這裏更新你的工作進度，如果太
久沒有看到你的工作進度報告，大巫師們會以爲以沒事做而指派工作給
，要是你仍然不理，也有可能會被假設成已經放棄巫師的工作而降回玩
家身分。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/wiz/hall1",
]));
	set("no_clean_up", 0);

	setup();
	call_other("/obj/board/wizard_j", "???");
	replace_program(ROOM);
}
