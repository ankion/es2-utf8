// edit.c

int edit(function callback)
{
	write("結束離開用 '.'，取消輸入用 '~q'，使用內建列編輯器用 '~e'。\n");
	write("—————————————————————————————\n");
	input_to("input_line", "", callback);
	return 1;
}

void input_line(string line, string text, function callback)
{
	if( line=="." ) {
		(*callback)(text);
		return;
	} else if( line=="~q" ) {
		write("輸入取消。\n");
		return;
	} else if( line=="~e" ) {
	} else
		text += line + "\n";
	input_to("input_line", text, callback);
}
