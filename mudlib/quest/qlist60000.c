inherit SKILL;

mapping *quest = ({
        ([      "quest":                "守城官兵",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               9 
        ]),
        ([      "quest":                "赫造基",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               9 
        ]),
        ([      "quest":                "獨眼頭陀",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5 
        ]),
        ([      "quest":                "芙雲",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               5
        ]),
        ([      "quest":                "夢玉樓",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8
        ]),
       ([      "quest":                "清雲",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
       ([      "quest":                "清玄",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

