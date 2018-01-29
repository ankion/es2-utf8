inherit ROOM;

void create()
{
	set("short","空房間");
	set("long",@LONG
這裏是 ES2 的「離島」管訓所, 如果你被送到這裏, 表示:
你違反了遊戲規則, 請好好的反省一下你的所作所爲, 想離
開的話只要斷線超過 15 分鐘即可 :-) 
LONG
	);
	setup();
}

void init()
{
	if (!wizardp(this_player())) 
	add_action("block_cmd","",1);
}

int block_cmd()
{
	if((string)query_verb() == "look") return 0;
	if((string)query_verb() == "help") return 0;
	return 1;
}
