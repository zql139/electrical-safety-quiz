#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "quiz.h"

void shuffleQuestions(Question questions[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

void copyQuestions(Question dest[], Question src[], int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = src[i];
    }
}

void displayQuestion(Question q, int index) {
    printf("%s\n\n", q.question);

    for (int i = 0; i < 4; i++) {
        printf("  %d. %s\n", i + 1, q.options[i]);
    }
}

int selectAnswer() {
    int choice;
    while (1) {
        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 4) {
            while (getchar() != '\n');
            return choice;
        } else {
            printf("输入错误，请输入 1-4 之间的数字: ");
            while (getchar() != '\n');
        }
    }
}

void displayResult(int score, int correct, int wrong) {
    printf("\n========================================\n");
    printf("            答题完成！\n");
    printf("========================================\n\n");

    printf("         最终得分: %d\n", score);
    printf("\n");
    printf("         答对: %d 题\n", correct);
    printf("         答错: %d 题\n", wrong);
    printf("\n");

    if (correct == QUIZ_COUNT) {
        printf("    太棒了！满分通过！\n");
        printf("    你对电气安全知识掌握得非常扎实！\n");
    } else if (correct >= 3) {
        printf("    表现不错！\n");
        printf("    电气安全知识还需要继续加强哦！\n");
    } else {
        printf("    继续加油！\n");
        printf("    建议重新学习电气安全常识，加强安全意识！\n");
    }

    printf("\n========================================\n");
    printf("        感谢参与电气安全答题！\n");
    printf("========================================\n");
}
