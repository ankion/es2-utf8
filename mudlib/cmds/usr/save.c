// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object link_ob;

        seteuid(getuid());

        if( !objectp(link_ob = me->query_temp("link_ob")) )
                return notify_fail("你不是經由正常連線進入，不能儲存。\n");

        if( environment(me)->query("valid_startroom") ) {
                me->set("startroom", base_name(environment(me)));
                write("當你下次連線進來時，會從這裏開始。\n");
        }

        if( (int)link_ob->save() && (int)me->save() ) {
        write("檔案儲存完畢。\n");
                return 1;
        } else {
                write("儲存失敗。\n");
                return 0;
        }
}

int help(object me)
{
        write(@HELP
指令格式：save

把你辛苦奮鬥的結果存起來。
HELP
        );
        return 1;
}
