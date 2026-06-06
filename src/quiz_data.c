#include <string.h>
#include "quiz.h"

void initializeQuestions(Question questions[]) {
    strcpy(questions[0].question, "发现有人触电时，首先应该怎么做？");
    strcpy(questions[0].options[0], "直接用手拉触电者");
    strcpy(questions[0].options[1], "立即切断电源");
    strcpy(questions[0].options[2], "马上做人工呼吸");
    strcpy(questions[0].options[3], "拨打120等待救援");
    questions[0].answer = 2;
    strcpy(questions[0].explanation, "触电救人前必须先切断电源，否则救人者也会触电。");

    strcpy(questions[1].question, "以下哪种情况最容易引发电气火灾？");
    strcpy(questions[1].options[0], "使用合格电器");
    strcpy(questions[1].options[1], "电线老化破损仍继续使用");
    strcpy(questions[1].options[2], "定期检查电路");
    strcpy(questions[1].options[3], "不在同一插座上使用多个大功率电器");
    questions[1].answer = 2;
    strcpy(questions[1].explanation, "老化破损的电线容易短路，产生高温引燃周围可燃物。");

    strcpy(questions[2].question, "湿手为什么不能触摸电器开关？");
    strcpy(questions[2].options[0], "水会损坏开关");
    strcpy(questions[2].options[1], "湿手容易滑落");
    strcpy(questions[2].options[2], "水能导电，容易造成触电");
    strcpy(questions[2].options[3], "没有任何危险");
    questions[2].answer = 3;
    strcpy(questions[2].explanation, "水是导体，湿手触摸开关会将电流传导到人体，造成触电事故。");

    strcpy(questions[3].question, "发现电器着火，首先应该？");
    strcpy(questions[3].options[0], "用水浇灭");
    strcpy(questions[3].options[1], "用灭火器扑灭");
    strcpy(questions[3].options[2], "立即切断电源");
    strcpy(questions[3].options[3], "逃离现场");
    questions[3].answer = 3;
    strcpy(questions[3].explanation, "电器着火时首先切断电源，再使用合适灭火器扑灭，切断电源是第一步。");

    strcpy(questions[4].question, "以下哪种行为是正确的用电习惯？");
    strcpy(questions[4].options[0], "私拉乱接电线");
    strcpy(questions[4].options[1], "使用绝缘破损的导线");
    strcpy(questions[4].options[2], "空调单独使用一个插座");
    strcpy(questions[4].options[3], "用铜丝代替保险丝");
    questions[4].answer = 3;
    strcpy(questions[4].explanation, "大功率电器如空调应单独使用插座，避免电路过载引发火灾。");

    strcpy(questions[5].question, "遇到雷雨天，以下哪种行为是错误的？");
    strcpy(questions[5].options[0], "避免在树下躲雨");
    strcpy(questions[5].options[1], "关闭电视等电器");
    strcpy(questions[5].options[2], "使用手机打电话");
    strcpy(questions[5].options[3], "远离电线杆和天线");
    questions[5].answer = 3;
    strcpy(questions[5].explanation, "雷雨天使用手机打电话容易被雷电击中，雷电流可通过手机信号线路传导。");

    strcpy(questions[6].question, "家庭电路保险丝的作用是？");
    strcpy(questions[6].options[0], "节省电费");
    strcpy(questions[6].options[1], "防止短路时造成火灾");
    strcpy(questions[6].options[2], "加快电流速度");
    strcpy(questions[6].options[3], "提高电器效率");
    questions[6].answer = 2;
    strcpy(questions[6].explanation, "保险丝在电流过大时自动熔断，切断电路，防止导线过热起火。");

    strcpy(questions[7].question, "以下哪种物品不能作为电气火灾灭火器使用？");
    strcpy(questions[7].options[0], "干粉灭火器");
    strcpy(questions[7].options[1], "二氧化碳灭火器");
    strcpy(questions[7].options[2], "水");
    strcpy(questions[7].options[3], "1211灭火器");
    questions[7].answer = 3;
    strcpy(questions[7].explanation, "水能导电，用水扑灭电器火灾会造成触电，应使用干粉或二氧化碳灭火器。");

    strcpy(questions[8].question, "如果看到电线断落在地上，应该怎么做？");
    strcpy(questions[8].options[0], "走过去仔细查看");
    strcpy(questions[8].options[1], "用木棍挑开电线");
    strcpy(questions[8].options[2], "保持安全距离并报告相关部门");
    strcpy(questions[8].options[3], "绕开即可，无需处理");
    questions[8].answer = 3;
    strcpy(questions[8].explanation, "断落的电线可能带电，靠近或触碰都会造成触电，应保持距离并报告电力部门。");

    strcpy(questions[9].question, "以下关于接地线的说法，正确的是？");
    strcpy(questions[9].options[0], "接地线可有可无");
    strcpy(questions[9].options[1], "接地线是为了防止触电事故");
    strcpy(questions[9].options[2], "所有电器都不需要接地");
    strcpy(questions[9].options[3], "接地线会增加耗电量");
    questions[9].answer = 2;
    strcpy(questions[9].explanation, "接地线将电器金属外壳与大地连接，漏电时电流导入大地，防止人体触电。");

    strcpy(questions[10].question, "使用移动电器时，应该注意什么？");
    strcpy(questions[10].options[0], "随意拉扯电线");
    strcpy(questions[10].options[1], "注意绝缘保护，避免破损");
    strcpy(questions[10].options[2], "可以在潮湿环境中使用");
    strcpy(questions[10].options[3], "不需要检查插头");
    questions[10].answer = 2;
    strcpy(questions[10].explanation, "移动电器要注意绝缘，避免电线破损露出导体造成触电。");

    strcpy(questions[11].question, "什么是电气安全的\"三做到\"？");
    strcpy(questions[11].options[0], "做到不节约、做到浪费电、做到乱用电");
    strcpy(questions[11].options[1], "做到思想重视、措施落实、定期检查");
    strcpy(questions[11].options[2], "做到随意使用、随意操作、随意维修");
    strcpy(questions[11].options[3], "做到省钱、省时、省力");
    questions[11].answer = 2;
    strcpy(questions[11].explanation, "电气安全三做到：思想重视、措施落实、定期检查，缺一不可。");

    strcpy(questions[12].question, "发生电气火灾时，正确的逃生方法是？");
    strcpy(questions[12].options[0], "乘坐电梯快速逃离");
    strcpy(questions[12].options[1], "用湿毛巾捂住口鼻，低姿前行");
    strcpy(questions[12].options[2], "返回火场取贵重物品");
    strcpy(questions[12].options[3], "在火中大声呼救");
    questions[12].answer = 2;
    strcpy(questions[12].explanation, "火灾产生的有毒烟雾会让人窒息，应用湿毛巾捂住口鼻，低姿逃离。");

    strcpy(questions[13].question, "临时用电应该注意什么？");
    strcpy(questions[13].options[0], "长期使用临时电线");
    strcpy(questions[13].options[1], "找专业人员安装，不私拉乱接");
    strcpy(questions[13].options[2], "只要能通电就行");
    strcpy(questions[13].options[3], "可以用花线作为电源线");
    questions[13].answer = 2;
    strcpy(questions[13].explanation, "临时用电必须请专业电工安装，私拉乱接容易造成触电和火灾事故。");

    strcpy(questions[14].question, "安全电压是指多少伏以下的电压？");
    strcpy(questions[14].options[0], "110V");
    strcpy(questions[14].options[1], "36V");
    strcpy(questions[14].options[2], "220V");
    strcpy(questions[14].options[3], "12V");
    questions[14].answer = 2;
    strcpy(questions[14].explanation, "安全电压为不高于36V，超过此电压人体触碰时可能有生命危险。");
}
