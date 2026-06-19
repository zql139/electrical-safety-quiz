/**
 * @file quiz_utils.c
 * @brief 工具函数模块
 * @version 3.0
 * 
 * 包含输入处理、结果显示等工具函数
 */

#include "quiz.h"

/* ==================== 输入处理 ==================== */

/**
 * @brief 清理输入缓冲区
 */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ==================== 界面显示 ==================== */

/**
 * @brief 显示欢迎界面
 */
void displayWelcome(void) {
    printf("\n");
    printf("========================================\n");
    printf("      电气安全常识课堂答题程序 v3.0\n");
    printf("========================================\n");
    printf("\n规则说明：\n");
    printf("  - 系统将随机抽取 %d 道选择题\n", QUIZ_COUNT);
    printf("  - 每题有 4 个选项，只有一个正确答案\n");
    printf("  - 答对 +1 分，答错 -1 分\n");
    printf("\n========================================\n");
    printf("\n按任意键开始答题...\n");
    getchar();
}

/**
 * @brief 显示答题结果
 * @param stats 统计信息指针
 */
void displayResult(QuizStats *stats) {
    printf("\n========================================\n");
    printf("             答题结束！\n");
    printf("========================================\n");
    printf("最终得分: %d 分\n", stats->final_score);
    printf("答对题目: %d 道\n", stats->correct_count);
    printf("答错题目: %d 道\n", stats->wrong_count);
    printf("========================================\n");
    
    // 根据得分显示评语
    if (stats->final_score >= 4) {
        printf("评语：太棒了！你对电气安全知识掌握得很好！\n");
    } else if (stats->final_score >= 2) {
        printf("评语：表现不错！继续加油学习电气安全知识。\n");
    } else if (stats->final_score >= 0) {
        printf("评语：还需要多加学习，注意电气安全常识。\n");
    } else {
        printf("评语：建议重新学习电气安全基础知识。\n");
    }
    
    printf("========================================\n");
}

/* ==================== 输入验证 ==================== */

/**
 * @brief 获取用户选择
 * @return 用户输入的选项(1-4)
 */
int getUserChoice(void) {
    int choice;
    while (scanf("%d", &choice) != 1) {
        printf("输入无效！请输入 1-4 的数字: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return choice;
}

/**
 * @brief 验证答案是否有效
 * @param choice 用户选择的答案
 * @return 1-有效，0-无效
 */
int validateAnswer(int choice) {
    return (choice >= 1 && choice <= 4);
}

/* ==================== 统计功能 ==================== */

/**
 * @brief 创建统计信息结构体
 * @return 分配的统计信息指针
 */
QuizStats* createStats(void) {
    QuizStats *stats = (QuizStats*)malloc(sizeof(QuizStats));
    if (stats != NULL) {
        stats->total_questions = 0;
        stats->correct_count = 0;
        stats->wrong_count = 0;
        stats->final_score = 0;
    }
    return stats;
}

/**
 * @brief 更新统计信息
 * @param stats 统计信息指针
 * @param result 答题结果指针
 */
void updateStats(QuizStats *stats, QuizResult *result) {
    stats->total_questions++;
    if (result->is_correct) {
        stats->correct_count++;
    } else {
        stats->wrong_count++;
    }
    stats->final_score += result->score_change;
}

/**
 * @brief 保存答题结果到文件
 * @param stats 统计信息
 * @param results 答题结果数组
 * @param count 结果数量
 */
void saveResultsToFile(QuizStats *stats, QuizResult *results, int count) {
    FILE *fp = fopen("output/run_result.txt", "w", encoding("utf-8"));
    if (fp == NULL) {
        printf("无法打开输出文件！\n");
        return;
    }
    
    fprintf(fp, "========================================\n");
    fprintf(fp, "      电气安全常识课堂答题程序 v3.0\n");
    fprintf(fp, "========================================\n");
    fprintf(fp, "\n最终得分: %d 分\n", stats->final_score);
    fprintf(fp, "答对题目: %d 道\n", stats->correct_count);
    fprintf(fp, "答错题目: %d 道\n", stats->wrong_count);
    fprintf(fp, "\n========================================\n");
    
    fclose(fp);
}
