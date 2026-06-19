/**
 * @file quiz.h
 * @brief 电气安全答题程序 - 头文件
 * @version 3.0
 * 
 * 本程序是一个模块化的电气安全常识选择题答题系统
 */

#ifndef QUIZ_H
#define QUIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/* ==================== 常量定义 ==================== */
#define MAX_QUESTIONS 15          // 题库最大题目数
#define QUIZ_COUNT 5              // 每次答题数量
#define MAX_QUESTION_LENGTH 200    // 题目最大长度
#define MAX_OPTION_LENGTH 100     // 选项最大长度
#define MAX_EXPLANATION_LENGTH 300 // 解释最大长度
#define MAX_NAME_LENGTH 50        // 题目类型名称最大长度

/* ==================== 数据结构 ==================== */

/**
 * @brief 题目结构体
 */
typedef struct {
    char question[MAX_QUESTION_LENGTH];       // 题目内容
    char options[4][MAX_OPTION_LENGTH];     // 四个选项
    int answer;                              // 正确答案编号(1-4)
    char explanation[MAX_EXPLANATION_LENGTH]; // 答错时的解释
    int difficulty;                           // 难度等级(1-简单,2-中等,3-困难)
    int category;                             // 题目分类
} Question;

/**
 * @brief 答题结果结构体
 */
typedef struct {
    int question_id;       // 题目编号
    int user_answer;       // 用户答案
    int correct_answer;    // 正确答案
    int is_correct;        // 是否正确
    int score_change;      // 分数变化
} QuizResult;

/**
 * @brief 统计信息结构体
 */
typedef struct {
    int total_questions;   // 总题目数
    int correct_count;     // 答对数量
    int wrong_count;       // 答错数量
    int final_score;       // 最终分数
} QuizStats;

/* ==================== 函数声明 ==================== */

/* 题库模块 - quiz_data.c */
void initQuestions(Question questions[]);
void shuffleQuestions(Question questions[], int n);
void selectRandomQuestions(Question all[], Question selected[], int total, int count);
void displayQuestion(Question *q, int question_num);

/* 工具模块 - quiz_utils.c */
void clearInputBuffer(void);
void displayWelcome(void);
void displayResult(QuizStats *stats);
int getUserChoice(void);
int validateAnswer(int choice);
QuizStats* createStats(void);
void updateStats(QuizStats *stats, QuizResult *result);
void saveResultsToFile(QuizStats *stats, QuizResult *results, int count);

/* 主程序 - main.c */
void runQuiz(void);

#endif /* QUIZ_H */
