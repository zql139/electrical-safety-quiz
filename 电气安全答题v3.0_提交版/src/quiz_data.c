/**
 * @file quiz_data.c
 * @brief 题库数据模块
 * @version 3.0
 * 
 * 包含15道电气安全常识选择题
 */

#include "quiz.h"

/* ==================== 题库数据 ==================== */

void initQuestions(Question questions[]) {
    // 初始化随机种子
    srand((unsigned int)time(NULL));
    
    // 题目1
    strcpy(questions[0].question, "当发现有人触电时，首先应该做什么？");
    strcpy(questions[0].options[0], "立即用手去拉触电者");
    strcpy(questions[0].options[1], "立即切断电源");
    strcpy(questions[0].options[2], "拨打急救电话");
    strcpy(questions[0].options[3], "用水泼触电者");
    questions[0].answer = 2;
    strcpy(questions[0].explanation, "触电救人前必须先切断电源，否则救人者也会触电。");
    questions[0].difficulty = 1;
    questions[0].category = 1;
    
    // 题目2
    strcpy(questions[1].question, "以下哪种灭火器适用于电气火灾？");
    strcpy(questions[1].options[0], "水基型灭火器");
    strcpy(questions[1].options[1], "干粉灭火器");
    strcpy(questions[1].options[2], "泡沫灭火器");
    strcpy(questions[1].options[3], "二氧化碳灭火器");
    questions[1].answer = 4;
    strcpy(questions[1].explanation, "电气火灾不能用水或泡沫灭火器，会导电引发二次触电。");
    questions[1].difficulty = 2;
    questions[1].category = 2;
    
    // 题目3
    strcpy(questions[2].question, "雷雨天气时，以下哪种做法是正确的？");
    strcpy(questions[2].options[0], "在大树下避雨");
    strcpy(questions[2].options[1], "远离金属物体");
    strcpy(questions[2].options[2], "使用手机通话");
    strcpy(questions[2].options[3], "在高处停留");
    questions[2].answer = 2;
    strcpy(questions[2].explanation, "金属容易引雷，雷雨天气应远离金属物体。");
    questions[2].difficulty = 1;
    questions[2].category = 3;
    
    // 题目4
    strcpy(questions[3].question, "家庭用电中，三孔插座的接地孔应该连接到哪里？");
    strcpy(questions[3].options[0], "零线");
    strcpy(questions[3].options[1], "火线");
    strcpy(questions[3].options[2], "地线");
    strcpy(questions[3].options[3], "不连接");
    questions[3].answer = 3;
    strcpy(questions[3].explanation, "接地孔连接地线，用于防止电器漏电时触电。");
    questions[3].difficulty = 2;
    questions[3].category = 1;
    
    // 题目5
    strcpy(questions[4].question, "发现电气设备冒烟起火，首先应该？");
    strcpy(questions[4].options[0], "用灭火器灭火");
    strcpy(questions[4].options[1], "切断电源");
    strcpy(questions[4].options[2], "拨打119");
    strcpy(questions[4].options[3], "用水浇灭");
    questions[4].answer = 2;
    strcpy(questions[4].explanation, "电气火灾必须先切断电源，再使用合适的灭火器灭火。");
    questions[4].difficulty = 1;
    questions[4].category = 2;
    
    // 题目6
    strcpy(questions[5].question, "以下哪种情况会导致触电？");
    strcpy(questions[5].options[0], "干燥的木椅子上双手触摸电线");
    strcpy(questions[5].options[1], "穿着绝缘鞋触摸火线");
    strcpy(questions[5].options[2], "双手同时触摸火线和零线");
    strcpy(questions[5].options[3], "站在绝缘体上触摸地线");
    questions[5].answer = 3;
    strcpy(questions[5].explanation, "双手同时接触火线和零线会形成回路，导致电流通过身体触电。");
    questions[5].difficulty = 2;
    questions[5].category = 1;
    
    // 题目7
    strcpy(questions[6].question, "使用移动电器时，以下哪项是安全做法？");
    strcpy(questions[6].options[0], "不用检查电线是否有破损");
    strcpy(questions[6].options[1], "可以在潮湿环境下使用");
    strcpy(questions[6].options[2], "使用前检查电线和插头是否完好");
    strcpy(questions[6].options[3], "超负荷使用也没关系");
    questions[6].answer = 3;
    strcpy(questions[6].explanation, "使用移动电器前应检查电线和插头，确保安全才能使用。");
    questions[6].difficulty = 1;
    questions[6].category = 1;
    
    // 题目8
    strcpy(questions[7].question, "发现有人被电击伤，以下处理方式正确的是？");
    strcpy(questions[7].options[0], "立即进行人工呼吸");
    strcpy(questions[7].options[1], "切断电源后再施救");
    strcpy(questions[7].options[2], "用水泼向伤者");
    strcpy(questions[7].options[3], "直接用手拉伤者");
    questions[7].answer = 2;
    strcpy(questions[7].explanation, "必须先切断电源，确保安全后才能对伤者进行急救。");
    questions[7].difficulty = 1;
    questions[7].category = 1;
    
    // 题目9
    strcpy(questions[8].question, "家庭电路保险丝断了，以下做法正确的是？");
    strcpy(questions[8].options[0], "用铜丝代替保险丝");
    strcpy(questions[8].options[1], "换成更大电流的保险丝");
    strcpy(questions[8].options[2], "查明原因后更换相同规格保险丝");
    strcpy(questions[8].options[3], "不换，继续使用");
    questions[8].answer = 3;
    strcpy(questions[8].explanation, "保险丝熔断说明电路有故障，应查明原因并更换相同规格的保险丝。");
    questions[8].difficulty = 2;
    questions[8].category = 1;
    
    // 题目10
    strcpy(questions[9].question, "以下关于接地说法正确的是？");
    strcpy(questions[9].options[0], "接地只是为了节省电线");
    strcpy(questions[9].options[1], "接地可以防止电器外壳带电时触电");
    strcpy(questions[9].options[2], "所有电器都不需要接地");
    strcpy(questions[9].options[3], "接地会增加触电风险");
    questions[9].answer = 2;
    strcpy(questions[9].explanation, "接地可以将电器外壳的电流引入大地，防止触电事故。");
    questions[9].difficulty = 2;
    questions[9].category = 1;
    
    // 题目11
    strcpy(questions[10].question, "电风扇运转时，以下哪种行为是危险的？");
    strcpy(questions[10].options[0], "在风扇前吹风纳凉");
    strcpy(questions[10].options[1], "用手指触摸风扇叶片");
    strcpy(questions[10].options[2], "远离运转的风扇");
    strcpy(questions[10].options[3], "定期清洁风扇叶片");
    questions[10].answer = 2;
    strcpy(questions[10].explanation, "触摸运转的风扇叶片可能被卷入，造成机械伤害和触电。");
    questions[10].difficulty = 1;
    questions[10].category = 1;
    
    // 题目12
    strcpy(questions[11].question, "拔插头时，以下哪种方式是正确的？");
    strcpy(questions[11].options[0], "直接拽拉电线");
    strcpy(questions[11].options[1], "握住插头身体部分拔出");
    strcpy(questions[11].options[2], "拖着电线走动");
    strcpy(questions[11].options[3], "用湿手拔插头");
    questions[11].answer = 2;
    strcpy(questions[11].explanation, "应握住插头部分拔出，直接拉电线会损坏电线和插座。");
    questions[11].difficulty = 1;
    questions[11].category = 1;
    
    // 题目13
    strcpy(questions[12].question, "当发现电线起火时，应该使用哪种灭火器？");
    strcpy(questions[12].options[0], "清水灭火器");
    strcpy(questions[12].options[1], "泡沫灭火器");
    strcpy(questions[12].options[2], "干粉或二氧化碳灭火器");
    strcpy(questions[12].options[3], "任何灭火器都可以");
    questions[12].answer = 3;
    strcpy(questions[12].explanation, "电气火灾应使用干粉或二氧化碳灭火器，水和泡沫会导电。");
    questions[12].difficulty = 2;
    questions[12].category = 2;
    
    // 题目14
    strcpy(questions[13].question, "以下哪种行为容易引起电气火灾？");
    strcpy(questions[13].options[0], "及时更换老化的电线");
    strcpy(questions[13].options[1], "在一个插座上使用多个大功率电器");
    strcpy(questions[13].options[2], "外出时关闭电源");
    strcpy(questions[13].options[3], "定期检查电路");
    questions[13].answer = 2;
    strcpy(questions[13].explanation, "一个插座使用多个大功率电器会导致过载，引发火灾。");
    questions[13].difficulty = 2;
    questions[13].category = 2;
    
    // 题目15
    strcpy(questions[14].question, "遇到高压电线落地时，应该怎么做？");
    strcpy(questions[14].options[0], "快速跑离落地点");
    strcpy(questions[14].options[1], "单脚或双脚并拢跳离落地点");
    strcpy(questions[14].options[2], "原地等待救援");
    strcpy(questions[14].options[3], "用木棒挑开电线");
    questions[14].answer = 2;
    strcpy(questions[14].explanation, "高压线落地点周围有跨步电压，应双脚并拢跳出危险区域。");
    questions[14].difficulty = 3;
    questions[14].category = 3;
}

/**
 * @brief 洗牌算法打乱题目顺序
 * @param questions 题目数组
 * @param n 题目数量
 */
void shuffleQuestions(Question questions[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

/**
 * @brief 随机选择指定数量的题目
 * @param all 全部题目数组
 * @param selected 选中的题目数组
 * @param total 总题目数
 * @param count 需要选择的数量
 */
void selectRandomQuestions(Question all[], Question selected[], int total, int count) {
    // 先复制所有题目
    Question temp[MAX_QUESTIONS];
    for (int i = 0; i < total; i++) {
        temp[i] = all[i];
    }
    
    // 打乱顺序
    shuffleQuestions(temp, total);
    
    // 选择前count个
    for (int i = 0; i < count && i < total; i++) {
        selected[i] = temp[i];
    }
}

/**
 * @brief 显示题目
 * @param q 题目指针
 * @param question_num 当前题号
 */
void displayQuestion(Question *q, int question_num) {
    printf("\n第 %d/%d 题：\n", question_num, QUIZ_COUNT);
    printf("%s\n", q->question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q->options[i]);
    }
    printf("\n请输入答案 (1-4): ");
}
