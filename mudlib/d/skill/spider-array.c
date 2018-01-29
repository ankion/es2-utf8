// sword.c

#include <ansi.h>

inherit SKILL;

int valid_skill_usage(string usage)
{
	return usage=="array";
}

int form_array(object leader)
{
	object *member;

	member = leader->query_team();
	if( sizeof(member) != 8 )
		return notify_fail("靈蛛劍陣共需八人，少一個多一個都不行。\n");
	message_vision( HIG "$N率領衆人四下站定八個方位，組成了「靈蛛劍陣」！\n" NOR, leader);
	return 1;
}
