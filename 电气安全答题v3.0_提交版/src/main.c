/**
 * @file main.c
 * @brief 主程序入口 - 模块化版本
 * @version 3.0
 * 
 * 电气安全常识课堂答题程序主程序
 * 采用模块化设计，代码结构清晰，易于维护
 */

#include "quiz.h"

/**
 * @brief 主函数
 * @return 程序退出码
 */
int main(void) {
    runQuiz();
    return 0;
}

/**
 * @brief 运行答题程序
 */
void runQuiz(void) {
    // 变量声明
    Question allQuestions[MAX_QUESTIONS];      // 全部题目
    Question selectedQuestions[QUIZ_COUNT];      // 选中的题目
    QuizResult results[QUIZ_COUNT];             // 答题结果
    QuizStats *stats;                           // 统计信息
    
    // 初始化
    initQuestions(allQuestions);
    selectRandomQuestions(allQuestions, selectedQuestions, MAX_QUESTIONS, QUIZ_COUNT);
    stats = createStats();
    
    if (stats == NULL) {
        printf("内存分配失败！\n");
        return;
    }
    
    // 显示欢迎界面
    displayWelcome();
    
    // 答题循环
    for (int i = 0; i < QUIZ_COUNT; i++) {
        int userAnswer;
        
        // 显示题目
        displayQuestion(&selectedQuestions[i], i + 1);
        
        // 获取用户输入
        userAnswer = getUserChoice();
        
        // 记录结果
        results[i].question_id = i + 1;
        results[i].user_answer = userAnswer;
        results[i].correct_answer = selectedQuestions[i].answer;
        results[i].is_correct = (userAnswer == selectedQuestions[i].answer);
        results[i].score_change = results[i].is_correct ? 1 : -1;
        
        // 更新统计
        updateStats(stats, &results[i]);
        
        // 显示反馈
        if (results[i].is_correct) {
            printf("\n*** 回答正确！+1分 ***\n");
        } else {
            printf("\n*** 回答错误！-1分 ***\n");
            printf("正确答案是: %d. %s\n", 
                   selectedQuestions[i].answer, 
                   selectedQuestions[i].options[selectedQuestions[i].answer - 1]);
            printf("\n【解释】%s\n", selectedQuestions[i].explanation);
        }
        
        printf("\n当前得分: %d\n", stats->final_score);
    }
    
    // 显示最终结果
    displayResult(stats);
    
    // 保存结果到文件
    saveResultsToFile(stats, results, QUIZ_COUNT);
    
    // 释放内存
    free(stats);
}
