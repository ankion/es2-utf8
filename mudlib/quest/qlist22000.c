inherit SKILL;

mapping *quest = ({
        ([      "quest":                "趟子手",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               9 
        ]),
        ([      "quest":                "土匪首領",
                "quest_type":           "殺",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               9 
        ]),
        ([      "quest":                "老隊長",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5 
        ]),
        ([      "quest":                "大隊長",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               5
        ]),
        ([      "quest":                "小隊長",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8
        ]),
        ([      "quest":                "小兵",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            15,
                "score" :               8 
        ]),
        ([      "quest":                "柳繪心",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               8
        ]),
       ([      "quest":                "老兵",
                "quest_type":           "殺",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
       ([      "quest":                "殭屍護法",
                "quest_type":           "殺",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15 
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

