inherit ROOM;

void create()
{
        set("short", "地牢");
        set("long", @LONG
這裏黑黑暗暗，幾乎伸手不見五指。唯一的光亮來自牆上忽明忽暗的
松油燈。地上和牆上佈滿了暗紅色的血痕，散發出陣陣腥氣。不斷傳來的
哀嚎聲在死沉的地牢裏迴盪，令人毛骨聳然。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
        "north" : __DIR__"tunnel1",
          "west" : __DIR__"tunnel6",
            "east" : __DIR__"tortureroom",
            ]));
            
                    setup();
                    replace_program(ROOM);
                    
}
                            