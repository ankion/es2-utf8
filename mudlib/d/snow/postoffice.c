// Room: /d/snow/postoffice.c

inherit ROOM;

void create()
{
	set("short", "雪亭驛");
	set("long", @LONG
這裏是負責雪亭鎮官府文書跟軍令往來的雪亭驛，但是因爲出了雪
亭鎮往北的野羊山近年來有盜匪盤據，官府的信差最近都改走東邊的飛
鳶棧道，所以雪亭驛來往的人就少了，驛站的官員索性就開始接一些百
姓的信件，一方面打發時間，一方面也有點事做以免被上級裁撤。驛站
大門口上懸著一塊木牌(sign)，上面寫了些字。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "牌子上寫道：
    奉喬陰府知縣令喻，本驛著日起收發事宜擴及官員百姓上下人
等通辦，官員及兵部該管軍士、官府衙役免費，一般良民百姓書信
收費每通十文，收信免費，物品收費依份量大小另計，貴重細軟倘
有遺失退費加五成賠償，不得異議。
",
]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"mstreet4",
	]));
	set("objects", ([
		__DIR__"npc/post_officer": 1,
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "你將信箱交回驛站。\n");
		destruct(mbox);
	}
	return 1;
}
