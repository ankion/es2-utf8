// Room: /d/choyin/tree_tomb.c

inherit ROOM;

void create()
{
	set("short", "樹王墳");
	set("long", @LONG
你現在來到了著名的「樹王墳」前，這裏是個高臺，中央約兩丈見方
的地上有一截巨大的樹樁，少說有三、四十人合抱那麼粗，樹樁中間有一
個大洞(hole)，望下去黑漆漆地，石臺靠南的地方還有一間小廟(shrine)
，東西南北四個方向都有階梯通往四面的街道。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"n_street3",
  "west" : __DIR__"w_street3",
  "south" : __DIR__"s_street3",
  "east" : __DIR__"e_street1",
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "hole" : "一個黑漆漆的大洞，看來像是什麼蛀蟲蛀出來的，可是天底下哪裏
有這麼大的蛀蟲？這個洞連人也進得去。
",
  "shrine" : "一間磚砌的小廟，廟裏供奉的當然就是「樹王公」，你注意到廟裏
樹王公的神像左手殘缺不全，木刻的神像竟然有一條條白蟻的痕跡，和
一般廟裏金身神像給人的印象不太一樣。
",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
