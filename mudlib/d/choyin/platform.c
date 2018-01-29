inherit ROOM;

void create()
{
        set("short", "雲臺");
        set("long", @LONG
姑射之巔，祥雲朵朵，瑞彩千條。藐姑射之山，有神人居焉，肌膚若冰雪，綽約如處子..
仙蹤難覓，只覺風聲颯然，雲開之出，凸現一座雲臺(platform)
LONG
        );
        set("item_desc", ([
                "platform":
                    "一座精雕細琢的玉臺,放有一矮几;几上立有玉瓶,幾株寒谷幽蘭
綻放其中.臺旁置一雲幡(flag),可是仙家寶物.\n",
                "flag":"此幡可翻雲覆雨,最好不要碰(touch)它.\n",
          ]) );      
        set("objects", ([
                __DIR__"npc/lboy" :2,
        ]) );

        setup();
        
} 


void init()
{     
        add_action("do_touch", "touch");
}


int thounder(object ob)

{
        int i;
        int damage;
        if( environment(ob) == this_object())
        {
        message_vision("剎那間彤雲密佈,山川改色.無數雷霆霹向$N...\n", ob);
        message_vision("$N頓時周身起火,七竅冒煙...\n", ob);
        tell_room("/d/choyin/platform","你聞到一股燒焦的味道.\n");                                                                         
        i = (int)ob->query("eff_kee");
        damage = random(10)+35  ;
        ob->set("eff_kee",(int) i - damage );
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
        if( environment(ob) == this_object())
        call_out("thounder",5, ob);
        }
        else

        return 1;
}


void close_passage()
{
        if( !query("exits/down") ) return;
 message("vision", "一道藍光過後,雲臺合攏了.\n",
                        this_object() );                      
        delete("exits/down");
}


int do_touch(string arg) 
{
       string dir;
       object ob;
       if( !arg || arg=="" ) return 0;

       if( arg=="flag" ) {
                write("你碰了雲幡,雲幡動了一下.....\n");
        if( interactive(( ob = this_player())) )
        remove_call_out("thounder");
        call_out("thounder", 15, ob);            
        message("vision", "白光一閃,雲臺忽地裂開\n",
                        this_object() );                       
        set("exits/down", __DIR__"stove");
        call_out("close_passage", 1);  
        return 1;
        }
}


