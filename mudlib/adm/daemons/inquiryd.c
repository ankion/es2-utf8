// inquiryd.c
// Created by Annihilator@ES2 (01-19-95)

// This function handles the default inquiry between ppls and npcs to
// make npc more talktive. This is the '<me> ask <ob> about <topic>'
// case.

#include <ansi.h>

int parse_inquiry(object me, object ob, string topic)
{
	switch( topic ) {
		case "name":
		case "名字":
			message_vision( CYN "$N向$n問道：敢問" + RANK_D->query_respect(ob)
				+ "尊姓大名？\n" NOR, me, ob);
			return 1;
		case "here":
		case "這裏":
			message_vision(CYN "$N向$n問道：這位" + RANK_D->query_respect(ob)
				+ "，" + RANK_D->query_self(me) + "初到貴寶地，不知這裏有些什麼風土人情？\n" NOR,
				me, ob);
			return 1;
		case "rumors":
		case "傳聞":
			message_vision(CYN "$N向$n問道：這位" + RANK_D->query_respect(ob)
				+ "，不知最近有沒有聽說什麼消息？\n" NOR, me, ob);
			return 1;
		default:
			return 0;
	}
}
