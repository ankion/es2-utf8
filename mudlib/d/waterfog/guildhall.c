// guildhall.c

inherit CLASS_GUILD;

void create()
{
        set("short", "水煙閣正廳");
        set("long", @LONG
這裏是水煙閣的正廳，簡單的陳設中透出一股尊貴不凡的氣派，一
張黝黑的太師椅端坐在大廳中央，這裏同時也是「武者」們議事的所在
，每年的正月十七都要在水煙閣外的「虹臺」推選武林盟主，然後在這
裏舉行登位大典。你可以看到北邊的牆上掛著一樟木匾(sign)，似乎寫
著一些有關成爲一名武者的事項。
LONG
        );
        set("exits", ([
                "south" : __DIR__"entrance",
        ]));
        set("item_desc", ([
                "sign": @TEXT
要成爲一名武者並不難，水煙閣隨時歡迎任何身家清白之人成爲我們的
一份子，只要你加入(join)武者同盟，就可以向同盟中的各大門派拜師
學藝。
TEXT
        ]) );

        set("objects", ([
                CLASS_D("fighter") + "champion":1,
                CLASS_D("fighter") + "master":1,
                CLASS_D("fighter") + "executioner":1
        ]) );
        set("valid_startroom", 1);
        setup();
        call_other("/obj/board/fighter_b", "???");
}
