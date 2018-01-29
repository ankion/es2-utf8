// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "黑店");
        set("long", @LONG
屋裏相當冷清, 外面的濃霧還不時地從半開著的門縫飄進來,
地面上散著一些破舊的物品, 不過光從外表已經無法分辨出那是些
什麼東西了. 牆上(wall)刻著一些潦草的字體, 牆角的一盞燈籠掙
扎似地發出一陣陣微弱的光芒, 也始得那些字看來格外的詭異.

LONG
	);
	set("exits", ([
	"west" : "/d/death/road1",
	]) );
	set("item_desc", ([
	"wall" : @WALL
幾行你勉強分辨得出來的字:
我被困在這裏了.... 我要回家啦!!!!!!!!!!!
                      ^^^^
                        靠自己啦...
什麼叫靠自己啊?!?!? 這裏連個活人都沒有...

看到你自己時問一下吧... 自己人都會互相幫忙的說.. 
                                    ^^^^
                                 你... 確... 定?!?!
喔.. 
WALL
	]) );
        setup();
        replace_program(ROOM);
}
