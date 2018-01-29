// Room: /d/choyin/club.c
# include <room.h>
# include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "草堂");
	set("long", @LONG
一間由白茅草搭成的草堂，室內僅有一竹榻，一矮几，四把竹椅．堂前一幅拓片裝裱精
致，上書:
      書有未曾經我讀
      事無不可對人言
矮几上攤有書卷(books)放着一支硃砂筆，一房歙硯竟題有嶽武穆藏，另幾張上好生宣． 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yard",
  "east" : __DIR__"fence",
]));
        set("no_fight", "1");
        set("no_magic", "1");
        set("item_desc", ([
                "books" : @TEXT
几上的書信手而放，裝幀古樸，竟是宋版書，還有幾卷漢碑原拓。你按捺不住好奇心想拿
起來(scratch)仔細研究一番。
TEXT
]));     

        create_door("west", "柴門", "west" , DOOR_CLOSED);    
	set("no_clean_up", 0);

	setup();
}

void init()
{
   add_action("do_pray","pray");
   add_action("do_dance","dancing");
   add_action("do_scratch","scratch");
}

int do_dance(string arg)
{
     message_vision("也不知道隱士怎麼弄的，$N無法跳出專注的舞步。\n",
                this_player());   
      return 1;
}               

int do_pray(string arg)
{
     message_vision("也不知道隱士怎麼弄的，$N的瑪瑙手鐲不靈驗了。\n",
                this_player());       
    return 1;
}               

int do_scratch(string arg)
{ 
  int ddt=0; 
  object book;
  object ob;

  ob = this_player();

  if( !arg || arg!="books" ) 
  return 0;
  else { ddt = ddt + 1; 
  message_vision("$N乘人不備，抓起一本書藏入懷中。\n\n",
                this_player()); 

  switch( random(3) ) {
                case 0: book = new("/d/choyin/npc/obj/book1");
                        book ->move(ob);
                        ob->set_temp("choyin/書", ddt); 
                        break;
                case 1: book = new("/d/choyin/npc/obj/book1");
                        book ->move(ob);
                        ob->set_temp("choyin/書", ddt); 
                        break;
                case 2: book =new("/d/choyin/npc/obj/book2");
                        book ->move(ob);
                        ob->set_temp("choyin/書", ddt); 
                        break; 
                      }
}
  return 1;
}


int valid_leave(object me, string dir)
{       string item;
        object obj;

        item = "book";
        if( !objectp(obj = present(item, me)) )  {
                tell_object(me, "你離開草堂!\n" NOR );
        }  else  {
            while(objectp(obj = present(item, me)) ) 
              { if ( me->query_temp("choyin/書") ) {
                tell_object(me, HIC "你將書放回到矮几。\n" NOR);
                obj = present(item, me); 
                destruct(obj);
                                                         }
           me->set_temp("choyin/\112\151", 0);   
              }        
                 }
        return 1;
} 
