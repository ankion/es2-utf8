// enforce.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int pts;

        if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("指令格式：enforce 
<使出幾成內力傷敵>|none");

        if( !me->query_skill_mapped("force") )
                return notify_fail("你必須先 enable 一種內功。\n");

        if( arg=="none" )
                me->delete("force_factor");
        else {
                if( pts < 0 || pts > (int)me->query_skill("force") / 2 )
                        return notify_fail("你只能用 none 
表示不運內力，或數字表示每一擊用幾點內力。\n");
                me->set("force_factor", pts);
        }

        write("Ok.\n");
        return 1;
}

int help (object me)
{
        write(@HELP
指令格式: enforce <使出幾點內力傷敵>|none
 
這個指令讓你指定每次擊中敵人時，要發出幾點內力傷敵。

enforce none 則表示你不使用內力。 

SEE ALSO : enable, enchant
HELP
        );
        return 1;
}
 
