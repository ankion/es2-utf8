inherit SKILL;

mapping *quest = ({
        ([      "quest":                "臥龍崗強盜",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               10 
        ]),
        ([      "quest":                "劉安祿",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               6 
        ]),
        ([      "quest":                "飛賊",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               4
        ]),
        ([      "quest":                "護寺武僧",
                "quest_type":           "殺",
                "time":                 400,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               5
        ]),
        ([      "quest":                "鄭屠夫",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8
        ]),
        ([      "quest":                "燒飯僧",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            15,
                "score" :               8 
        ]),
        ([      "quest":                "殭屍侍者",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               8
        ]),
       ([      "quest":                "昭儀",
                "quest_type":           "殺",
                "time":                 250,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
       ([      "quest":                "土匪嘍羅",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15 
        ]),
       ([      "quest":                "巨巖蛭",
                "quest_type":           "殺",
                "time":                 330,
                "exp_bonus":            10,
                "pot_bonus":            10,
                "score" :               9
        ]),
       ([      "quest":                "土匪爪牙",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            10,
                "pot_bonus":            10,
                "score" :               8
        ]),
       ([      "quest":                "柳繪心",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
       ([      "quest":                "老兵",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8 
        ]),
        ([      "quest":                "趟子手",
                "quest_type":           "殺",
                "time":                 540,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               8
        ]),
        ([      "quest":                "後備兵",
                "quest_type":           "殺",
                "time":                 480,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "旅客",
                "quest_type":           "殺",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "書生",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               10 
        ]),
        ([      "quest":                "綵衣少女",
                "quest_type":           "殺",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "船伕",
                "quest_type":           "殺",
                "time":                 150,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5 
        ]),
        ([      "quest":                "明心",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               8 
        ]),
        ([      "quest":                "跛僧人",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               8 
        ]),
        ([      "quest":                "僕役",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               3
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

