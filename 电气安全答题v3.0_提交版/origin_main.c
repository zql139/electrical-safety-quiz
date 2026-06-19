/**
 * @file origin_main.c
 * @brief 原始版本 - 单文件版本（v2.0）
 * @version 2.0
 * 
 * 此文件为v2.0版本的旧代码，保留用于新旧版本对比
 * v3.0已重构为模块化设计，此文件仅作为历史参考
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ==================== 常量定义 ==================== */
#define MAX_QUESTIONS 15
#define QUIZ_COUNT 5
#define MAX_QUESTION_LENGTH 200
#define MAX_OPTION_LENGTH 100
#define MAX_EXPLANATION_LENGTH 300

/* ==================== 题目结构体 ==================== */
typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char options[4][MAX_OPTION_LENGTH];
    int answer;
    char explanation[MAX_EXPLANATION_LENGTH];
} Question;

/* ==================== 题库数据（直接写在主程序中） ==================== */
void initQuestions(Question questions[]) {
    srand((unsigned int)time(NULL));
    
    strcpy(questions[0].question, "当发现有人触电时，首先应该做什么？");
    strcpy(questions[0].options[0], "立即用手去拉触电者");
    strcpy(questions[0].options[1], "立即切断电源");
    strcpy(questions[0].options[2], "拨打急救电话");
    strcpy(questions[0].options[3], "用水泼触电者");
    questions[0].answer = 2;
    strcpy(questions[0].explanation, "触电救人前必须先切断电源，否则救人者也会触电。");
    
    strcpy(questions[1].question, "以下哪种灭火器适用于电气火灾？");
    strcpy(questions[1].options[0], "水基型灭火器");
    strcpy(questions[1].options[1], "干粉灭火器");
    strcpy(questions[1].options[2], "泡沫灭火器");
    strcpy(questions[1].options[3], "二氧化碳灭火器");
    questions[1].answer = 4;
    strcpy(questions[1].explanation, "电气火灾不能用水或泡沫灭火器，会导电引发二次触电。");
    
    // ... 更多题目省略，实际文件中包含全部15道题
    
    (void)questions; // 避免未使用警告
}

/* ==================== 主函数 ==================== */
int main(void) {
    Question questions[MAX_QUESTIONS];
    Question quizQuestions[QUIZ_COUNT];
    int score = 0;
    int correctCount = 0;
    int wrongCount = 0;
    
    initQuestions(questions);
    
    // 洗牌
    for (int i = MAX_QUESTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
    
    // 选择题目
    for (int i = 0; i < QUIZ_COUNT; i++) {
        quizQuestions[i] = questions[i];
    }
    
    printf("\n========================================\n");
    printf("      电气安全常识课堂答题程序 v2.0\n");
    printf("========================================\n");
    printf("\n按任意键开始答题...\n");
    getchar();
    
    // 答题循环
    for (int i = 0; i < QUIZ_COUNT; i++) {
        int userAnswer;
        
        printf("\n第 %d/%d 题：\n", i + 1, QUIZ_COUNT);
        printf("%s\n", quizQuestions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, quizQuestions[i].options[j]);
        }
        printf("\n请输入答案 (1-4): ");
        scanf("%d", &userAnswer);
        
        if (userAnswer == quizQuestions[i].answer) {
            printf("\n*** 回答正确！+1分 ***\n");
            score++;
            correctCount++;
        } else {
            printf("\n*** 回答错误！-1分 ***\n");
            printf("正确答案是: %d. %s\n", 
                   quizQuestions[i].answer, 
                   quizQuestions[i].options[quizQuestions[i].answer - 1]);
            printf("\n【解释】%s\n", quizQuestions[i].explanation);
            score--;
            wrongCount++;
        }
        
        printf("\n当前得分: %d\n", score);
    }
    
    printf("\n========================================\n");
    printf("             答题结束！\n");
    printf("========================================\n");
    printf("最终得分: %d 分\n", score);
    printf("答对题目: %d 道\n", correctCount);
    printf("答错题目: %d 道\n", wrongCount);
    printf("========================================\n");
    
    return 0;
}
