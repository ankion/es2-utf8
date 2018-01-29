// Room: /d/temple/road1.c

inherit ROOM;

void create()
{
	set("short", "青石小徑");
	set("long", @LONG
一條鋪著青石板的小徑, 兩側高大的松樹, 偶有松針緩緩飄落。
樹幹上佈滿了青苔, 甚至還有些蔓延到石板上。南邊通往回廊, 西側
則是後殿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/temple/corridor3",
  "northwest" : "/d/temple/road2",
]));

	setup();
}

int valid_leave(object me, string dir)
{
     if (!wizardp(this_player()) && (dir=="south" || dir=="northwest"))
          {
           if( random((int)this_player()->query("kar")) < 3 )
              {
               message_vision("$N一腳踩在青苔上, 不小心滑了一跤, 四腳朝天地摔在地上起不來。\n\n\n", this_player());
               this_player()->unconcious();
               return 0;
              }
           else return ::valid_leave(me, dir);
          }
     else return ::valid_leave(me ,dir);
} 
         
