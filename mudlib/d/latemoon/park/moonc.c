inherit ROOM;

void create()
{
    set("short", "翠嶂");
	set("long", @LONG
穿過一層竹籬、花嶂編的月洞門，在你眼前出現的是那由粉牆環
護，綠柳周垂的翠嶂。兩邊分別是遊廊相接通往桃花林與長廊曲洞。
在這兒一棵西府海棠(flower)吸引你的注意，只見其勢若傘，絲垂翠
縷，葩吐丹砂，十分漂亮。
LONG
	);
    set("item_desc", ([
        "flower" : @TEXT
    你仔細看這是一棵形狀有些奇特的西府海棠，有一淡淡
的奇異香氣。原來在旁邊還有一朵不太起眼，但是略成金黃
色的小花蕊，你的直覺告訴你它似乎是一種珍貴藥材。你想
把它摘下(pick)。
TEXT
    ]) );
	set("exits", ([ /* sizeof() == 2 */
      "north" :__DIR__"flower2",
      "south" :__DIR__"bridge1",
      "west" :__DIR__"moon2",
      "east" :__DIR__"moon1",

]));

    set("objects", ([
    ]) );
	setup();

}
void init()
{
            add_action("do_pick","pick");
}
void reset()
{
        ::reset();
        set("pick_available" , 2);
}
int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="flower" )
              return notify_fail("你要摘取什麼? \n");
       if ( query("pick_available") )  {
       message_vision("$N從西府海棠中摘下一朵小花蕊。\n",this_player() );
       obj = new ("/d/latemoon/park/npc/obj/flower");
       obj->move(me);
       add("pick_available", -1);
       }
       return 1;
}
