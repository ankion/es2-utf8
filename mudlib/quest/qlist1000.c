inherit SKILL;

mapping *quest = ({
        ([      "quest":                "乞丐",
                "quest_type":           "殺",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               6
        ]),
        ([      "quest":                "李師師",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            15,
                "score" :               5
        ]),
        ([      "quest":                "寶官",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               4
        ]),
        ([      "quest":                "知客僧",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "裁縫",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            40,
                "score" :               8
        ]),
        ([      "quest":                "茶工",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            28,
                "pot_bonus":            18,
                "score" :               12
        ]),
        ([      "quest":                "瘋狗",
                "quest_type":           "殺",
                "time":                 40,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "野狗",
                "quest_type":           "殺",
                "time":                 40,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               5
        ]),
        ([      "quest":                "杜寬",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               8
        ]),
        ([      "quest":                "收破爛的",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            15,
                "score" :               12
        ]),
       ([      "quest":                "王鐵匠",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               8
        ]),
        ([      "quest":                "掃地僧",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            35,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "進香客",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               10
        ]),
       ([      "quest":                "魏無極",
                "quest_type":           "殺",
                "time":                 40,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
       ([      "quest":                "武館弟子",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               20
        ]),
        ([      "quest":                "賣餅大叔",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               8
        ]),
        ([      "quest":                "賣糖葫蘆的",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "賣包子的",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               8
        ]),
        ([      "quest":                "家丁",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "巖蛭",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            50,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "蜘蛛",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "金絲雀",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "藥僧",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

