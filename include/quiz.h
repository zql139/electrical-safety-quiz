#ifndef QUIZ_H
#define QUIZ_H

#define MAX_QUESTIONS 15
#define QUIZ_COUNT 5
#define MAX_OPTION_LENGTH 100
#define MAX_QUESTION_LENGTH 200
#define MAX_EXPLANATION_LENGTH 150

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char options[4][MAX_OPTION_LENGTH];
    int answer;
    char explanation[MAX_EXPLANATION_LENGTH];
} Question;

void initializeQuestions(Question questions[]);
void shuffleQuestions(Question questions[], int n);
void displayQuestion(Question q, int index);
int selectAnswer();
void displayResult(int score, int correct, int wrong);
void copyQuestions(Question dest[], Question src[], int count);

#endif /* QUIZ_H */
