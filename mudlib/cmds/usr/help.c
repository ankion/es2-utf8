// help.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

string *default_search = DEFAULT_SEARCH_PATHS;

int main(object me, string arg)
{
	int i;
	string file, *search;

	// If no topic specified, give the topics.
	if( !arg ) {
		cat(HELP_DIR + "help/topics");
		return 1;
	}

	// Else, try if a command name is specified.
	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("有這個指令存在，但是並沒有詳細的說明文件。\n");
		return file->help(me);
	}

	// Search the individual search path first.
	if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}

	// Support efun/lfun help with same name as other topics such as
	// ed() and ed command.
	sscanf(arg, "%s()", arg);

	// Finally, search the default search paths.
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more( read_file(default_search[i] + arg) );
			return 1;
		}
	}

	return notify_fail("沒有針對這項主題的說明文件。\n");
}

int help(object me)
{
	write(@HELP
指令格式：help <主題>              例如：> help cmds
          help <函數名稱>()        例如：> help call_out()

這個指令提供你針對某一主題的詳細說明文件，若是不指定主題，則提供你有關
主題的文件。
HELP
	);
	return 1;
}

