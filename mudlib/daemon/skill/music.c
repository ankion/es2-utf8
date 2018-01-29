// music. 

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
        int s;

        s = me->query_skill("music", 1);
        if( s%10==9 && (int)me->query("spi") < s/4) {
                tell_object(me, HIW
"由於你學習音律之學有成，你的靈性提高了\n" NOR);
                me->add("spi", 2);
        }
}

