// ask.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *msg_dunno = ({
  "$n搖搖頭，說道：沒聽說過。\n",
  "$n睜大眼睛望著$N，顯然不知道$P在說什麼。\n",
  "$n聳了聳肩，很抱歉地說：無可奉告。\n",
  "$n說道：嗯....這我可不清楚，你最好問問別人吧。\n",
  "$n想了一會兒，說道：對不起，你問的事我實在沒有印象。\n"
});

int main(object me, string arg)
{
  string dest, topic, msg, att, *id;
  object ob;
  mapping inq;
  int i;

  seteuid(getuid());

  if( !arg )
      return notify_fail("你要問誰什麼事？\n");

  if( sscanf(arg, "%s about %s", dest, topic)==2 )
    ;
  else if( sscanf(arg, "%s", dest)==1 ) {
    topic = "";
  } else
      return notify_fail("你要問誰什麼事？\n");

  if( !objectp(ob = present(dest, environment(me))) )
      return notify_fail("這裏沒有這個人。\n");

  if( !ob->is_character() ) {
      message_vision("$N對著$n自言自語....\n", me, ob);
      return 1;
  }

  if(topic == "") {
    if( mapp(inq = ob->query("inquiry")) ) {
      id = keys(inq);
      msg = "你可以打聽這些事情：\n";
      msg += sprintf("※『這裏』\n※『名字』\n※『傳聞』\n" );
      for(i=0; i<sizeof(id); i++) {
        msg += sprintf("※『%s』\n", id[i] );
      }
      write(msg);
      return 1;
    } else {
      topic = "詢問";
    }
  }

  if( !ob->query("can_speak") ) {
    message_vision("$N向$n打聽有關『" + topic + "』的消息，但是$p顯然聽不懂人話。\n", me, ob);
    return 1;
  }

  if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
    message_vision("$N向$n打聽有關『" + topic + "』的消息。\n", me, ob);

  if( userp(ob) ) return 1;
  if( !living(ob) ) {
    message_vision("但是很顯然的，$n現在的狀況沒有辦法給$N任何答覆。\n", me, ob);
    return 1;
  }

  if( msg = ob->query("inquiry/" + topic) ) {
    if( stringp(msg) ) {
        message_vision( CYN "$N說道：" + msg + "\n" NOR, ob);
        return 1;
    } else if( arrayp(msg) ) {
      for(i=0; i<sizeof(msg); i++) {
        if(stringp(msg[i])) {
          message_vision( CYN "$N說道：" + msg[i] + "\n" NOR, ob);
        } else if(functionp(msg[i])) {
        }
      }
    }
  } else if ( ob->query("name") == topic || topic == "name" || topic == "名字" ) {
      att = ob->query("attitude");
      switch (att)
      {
      case "aggressive":
      case "killer":
          message_vision(YEL"$N對$n把眼一瞪："+RANK_D->query_self_rude(ob)
              +"的名字是可以隨便提的嗎？！我看你這"+RANK_D->query_rude(me)
              +"是活膩了！\n"NOR, ob, me);
          break;	
      case "heroism":
          message_vision(CYN"$N對$n哈哈一笑："+ob->query("name")+"便是"
              +RANK_D->query_self_rude(ob)+"！\n"NOR, ob, me);
          break;
      case "peaceful":
      case "friendly":
      default:
          message_vision(CYN"$N對$n作了一揖：這位"+RANK_D->query_respect(me)
              +"可真會開玩笑，怎麼會突然問起"+RANK_D->query_self(ob)
              +"的名字？\n"NOR, ob, me);
          EMOTE_D->do_emote(ob, "sigh", ob->query("id"), 0);
          break;
      }	

      return 1;

  } else {
    switch(topic)
    {
    case "here":
    case "這裏":
      message_vision(CYN "$n對$N說道：這裏是" + environment(ob)->query("short") + "，至於其它的，" + RANK_D->query_self(ob) + "不便多說。\n" NOR, me, ob);
      break;
    default:
      message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
    }
  }

  return 1;
}

int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

這個指令在解謎時很重要, 通常必須藉由此一指令才能
獲得進一步的資訊。
HELP
   );
   return 1;
}
