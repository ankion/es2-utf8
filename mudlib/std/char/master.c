#include <dbase.h>
#include <login.h>

int prevent_learn(object me, string skill)
{
        int betrayer;

        if( betrayer = me->query("betrayer") ) {
                if( me->query_skill(skill, 1) >= 
this_object()->query_skill(skill, 1) - betrayer * 20 ) {
                        
message_vision("$N神色間似乎對$n不是十分信任，也許是想起$p從前背叛師門的事情 
...。\n",
                                this_object(), me );
                        command("say 嗯 .... 
師父能教你的都教了，其他的你自己練吧。");
                        return 1;
                }
        }

        if( !me->is_apprentice_of(this_object())
        &&      (int)this_object()->query_skill(skill, 1) <= 
(int)me->query_skill(skill, 1) * 3 ) {
                command("hmm");
                command("pat " + me->query("id"));
                command("say 雖然你是我門下的弟子，可是並非我的嫡傳弟子 
....");
                command("say 
我只能教你這些粗淺的本門功夫，其他的還是去找你師父學吧。");
                return 1;
        }

        return 0;
}
 
