#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_OPTIONS 4
#define TOTAL_QUESTIONS 3
typedef struct 
{
    char question_text[256];
    char options[MAX_OPTIONS][64];
    char correct_option;
} QuizQuestion;
void display_question(QuizQuestion q, int question_num);
char get_user_answer();
void run_quiz(QuizQuestion quiz[]);

int main() 
{
    QuizQuestion quiz[TOTAL_QUESTIONS] = 
    {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Python", "B. Java", "C. C Language", "D. C++"},
            'C'
        },
        {
            "Who is credited with creating the C programming language?",
            {"A. Dennis Ritchie", "B. James Gosling", "C. Guido van Rossum", "Bjarne Stroustrup"},
            'A'
        },
        {
            "Which format specifier is used to print a string in C?",
            {"A. %d", "B. %c", "C. %f", "D. %s"},
            'D'
        }
    };

    printf("=========================================\n");
    printf("     WELCOME TO THE C PROGRAMMING QUIZ    \n");
    printf("=========================================\n\n");

    run_quiz(quiz);

    return 0;
}
void display_question(QuizQuestion q, int question_num) {
    printf("-----------------------------------------\n");
    printf("Question %d: %s\n", question_num, q.question_text);
    printf("-----------------------------------------\n");
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%s\n", q.options[i]);
    }
    printf("-----------------------------------------\n");
}
char get_user_answer() 
{
    char ans;
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &ans); 
    return toupper(ans);
}
void run_quiz(QuizQuestion quiz[]) 
{
    int final_score = 0;
    for (int i = 0; i < TOTAL_QUESTIONS; i++) 
    {
        display_question(quiz[i], i + 1);
        char user_choice = get_user_answer();

        if (user_choice == quiz[i].correct_option) 
        {
            printf("\n✅ Correct Answer!\n\n");
            final_score++;
        } 
        else 
        {
            printf("\n❌ Wrong Answer. The correct option was %c.\n\n", quiz[i].correct_option);
        }
    }

    printf("=========================================\n");
    printf("               QUIZ OVER                 \n");
    printf("=========================================\n");
    printf("Your Final Score: %d out of %d\n", final_score, TOTAL_QUESTIONS);
    float percentage = ((float)final_score / TOTAL_QUESTIONS) * 100;
    printf("Percentage Secured: %.2f%%\n", percentage);
    printf("=========================================\n");
}
