// go.c

inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"東",
	"west":			"西",
	"northup":		"北邊",
	"southup":		"南邊",
	"eastup":		"東邊",
	"westup":		"西邊",
	"northdown":	"北邊",
	"southdown":	"南邊",
	"eastdown":		"東邊",
	"westdown":		"西邊",
	"northeast":	"東北",
	"northwest":	"西北",
	"southeast":	"東南",
	"southwest":	"西南",
	"up":			"上",
	"down":			"下",
	"out":			"外",
	"enter":        "裏",
]);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, mout, min, dir;
	object env, obj;
	mapping exit;

	if( !arg ) return notify_fail("你要往哪個方向走？\n");

	if( me->over_encumbranced() )
		return notify_fail("你的負荷過重，動彈不得。\n");

	if( me->is_busy() )
		return notify_fail("你的動作還沒有完成，不能移動。\n");

	env = environment(me);
	if(!env) return notify_fail("你哪裏也去不了。\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("這個方向沒有出路。\n");
		else
			return 0;
	}

	dest = exit[arg];

	if( !(obj = find_object(dest)) )
		call_other(dest, "???");
	if( !(obj = find_object(dest)) )
		return notify_fail("無法移動。\n");

	if( !env->valid_leave(me, arg) ) return 0;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	if( me->is_fighting() ) {
		mout = "往" + dir + "落荒而逃了。\n";
		min = "跌跌撞撞地跑了過來，模樣有些狼狽。\n";
	} else {
		mout = "往" + dir + "離開。\n";
		min = "走了過來。\n";
	}

	message( "vision", me->name() + mout, environment(me), ({me}) );
	if( me->move(obj) ) {
		me->remove_all_enemy();
		message( "vision", me->name() + min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;
    string arg, dir;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "看來該找機會逃跑了...\n");

    arg = directions[random(sizeof(directions))];

    if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	tell_object(me, "你慌里慌張往" + dir + "(" + arg + ")逃去...\n");

    main(me, arg);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
讓你往指定的方向移動。
 
HELP
    );
    return 1;
}
