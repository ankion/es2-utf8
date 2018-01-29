
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("密函", ({ "secret letter","letter"  }) );
    set("unit", "封");
    set("long","這是一封用蠟密封起來的信件，上面有一奇怪的圖案。\n");
    set_weight(50);
    setup();
}
void init()
{
             seteuid(getuid(environment()));
             add_action("do_fire","fire");
}

int do_fire(string arg)
{
       object me,obj;
       string item;

       me = this_player();
       item = "fire";
       if( !objectp(obj = present(item, me)) )
           return notify_fail("你身上沒有火沒法燒。\n");
       tell_object(me, HIY "你看見密函上出現幾行字 : \n" +
           HIM "師父: \n" +
               "      展信愉悅 \n" +
               "    徒兒在晚月莊作客已有一陣子了!\n" +
               "在這徒兒無意中發現晚月莊的祕密。\n" +
               "一、原來晚月莊主是同性戀，她似乎在對男人失望之餘，\n" +
               "    對比自己年輕的姑娘由恨轉而成一種變相畸型的愛。\n" +
               "二、在密室之中藏有一祕笈。以及莊內有一處有神奇寶物\n" +
               "    瑪瑙手鐲。在另一神祕的地方有通往莊主祕密情人的\n" +
               "    密室入口。\n" +
               "三、在莊內小花池中有火神族的神像。小花池似乎有神奇\n" +
               "    的力量在裏頭。\n" +
               "\n\n" NOR);
       return 1;
}
