#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quiz.h"

int main() {
    system("chcp 65001 > nul");

    Question allQuestions[MAX_QUESTIONS];
    Question quizQuestions[QUIZ_COUNT];
    int score = 0;
    int correct = 0;
    int wrong = 0;
    int userAnswer;

    srand(time(NULL));

    initializeQuestions(allQuestions);
    shuffleQuestions(allQuestions, MAX_QUESTIONS);
    copyQuestions(quizQuestions, allQuestions, QUIZ_COUNT);

    printf("\n========================================\n");
    printf("     欢迎参加电气安全常识课堂答题\n");
    printf("========================================\n");
    printf("\n规则说明：\n");
    printf("  - 系统将随机抽取 %d 道选择题\n", QUIZ_COUNT);
    printf("  - 每题有 4 个选项，仅有一个正确答案\n");
    printf("  - 答对 +1 分，答错 -1 分\n");
    printf("========================================\n");
    printf("\n按任意键开始答题...\n");
    getchar();

    for (int i = 0; i < QUIZ_COUNT; i++) {
        system("cls");
        printf("\n========================================\n");
        printf("第 %d/%d 题", i + 1, QUIZ_COUNT);
        printf("                    当前得分: %d\n", score);
        printf("========================================\n\n");

        displayQuestion(quizQuestions[i], i);

        printf("\n请输入你的答案 (1-4): ");
        userAnswer = selectAnswer();

        if (userAnswer == quizQuestions[i].answer) {
            printf("\n*** 回答正确！+1分 ***\n");
            score += 1;
            correct += 1;
        } else {
            printf("\n*** 回答错误！-1分 ***\n");
            printf("正确答案是: %d. %s\n", quizQuestions[i].answer,
                   quizQuestions[i].options[quizQuestions[i].answer - 1]);
            printf("\n【解释】%s\n", quizQuestions[i].explanation);
            score -= 1;
            wrong += 1;
        }

        printf("\n按任意键继续下一题...\n");
        getchar();
    }

    system("cls");
    displayResult(score, correct, wrong);

    return 0;
}
