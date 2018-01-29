// Room: /d/waterfog/swordtomb.c

inherit ROOM;

void create()
{
	set("short", "葬劍亭");
	set("long", @LONG
你現在來到一個山腰靠近山頂的亭子，亭子前立著一個兩丈多高的
石碑(monolith)，從亭子裏遠眺北方連綿不盡的大山，使你不禁感到胸
臆之間一股英雄情懷油然而生，葬劍亭據說每到夏日夜晚，野風吹過，
會產生一陣陣嗚嗚的哭泣聲，這也是水煙十景中的「孤亭劍泣」。出了
亭子，往南便是直通虹臺的石階，一條黃土小路往西通往另一條下山的
小路。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "monolith" : "石碑上龍飛鳳武地刻著幾個大字：

    風波劍神黎紅藥前輩葬劍於此，水煙閣第四代七長老比武
    不勝，以奸計害人而自取其辱，武者皆不齒其小人行徑，
    合力擊殺於此，甲辰年立此亭書銘其事以爲後人殷鑑。

                        第三代水煙閣主 於蘭玫音
                        第四代水煙閣主 聶    言   合立
                        第五代水煙閣主 段 柏 山
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/waterfog/wpath5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
