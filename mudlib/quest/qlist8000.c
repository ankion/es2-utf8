inherit SKILL;

mapping *quest = ({
        ([      "quest":                "鄭屠夫",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "臥龍崗強盜",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            35,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "綵衣少女",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "護寺武僧",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               15
        ]),
        ([      "quest":                "飛賊",
                "quest_type":           "殺",
                "time":                 600,
                "exp_bonus":            40,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "農夫",
                "quest_type":           "殺",
                "time":                 120,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               12
        ]),
        ([      "quest":                "旅客",
                "quest_type":           "殺",
                "time":                 200,
                "exp_bonus":            25,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "樵夫",
                "quest_type":           "殺",
                "time":                 120,
                "exp_bonus":            15,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "肥巖蛭",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "大巖蛭",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            25,
                "score" :               10
        ]),
        ([      "quest":                "巨巖蛭",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            50,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "土匪爪牙",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            45,
                "pot_bonus":            35,
                "score" :               10
        ]),
        ([      "quest":                "昭儀",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "圓春",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "惜春",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            15,
                "score" :               10
        ]),
        ([      "quest":                "跛僧人",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            10,
                "score" :               10
        ]),
        ([      "quest":                "殭屍侍者",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            35,
                "pot_bonus":            30,
                "score" :               10
        ]),
        ([      "quest":                "明心",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            25,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "清虛",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            35,
                "pot_bonus":            20,
                "score" :               10
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

