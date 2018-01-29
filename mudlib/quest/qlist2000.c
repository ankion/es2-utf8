inherit SKILL;

mapping *quest = ({
        ([      "quest":                "船伕",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "潘若秋",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "弈者",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            24,
                "score" :               10
        ]),
        ([      "quest":                "寶官",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            24,
                "pot_bonus":            16,
                "score" :               10
        ]),
        ([      "quest":                "化緣和尚",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            38,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "知客僧",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               15
        ]),
        ([      "quest":                "鴇母",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "雜貨販",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "裁縫",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               18
        ]),
        ([      "quest":                "農夫",
                "quest_type":           "殺",
                "time":                 600,
                "exp_bonus":            50,
                "pot_bonus":            30,
                "score" :               12
        ]),
        ([      "quest":                "李火獅",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            28,
                "pot_bonus":            26,
                "score" :               10
        ]),
        ([      "quest":                "杜寬",
                "quest_type":           "殺",
                "time":                 50,
                "exp_bonus":            24,
                "pot_bonus":            20,
                "score" :               12
        ]),
        ([      "quest":                "旅客",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            40,
                "score" :               10
        ]),
        ([      "quest":                "樵夫",
                "quest_type":           "殺",
                "time":                 600,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "貴公子",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "巖蛭",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "玄真",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            25,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "蜘蛛",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            16,
                "score" :               10
        ]),
        ([      "quest":                "蝴蝶",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            36,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "芳綾",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "金絲雀",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "藥僧",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            18,
                "score" :               10
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

