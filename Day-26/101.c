#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() 
{
    int secret_number, guess;
    int attempts = 0;
    srand(time(NULL));
    secret_number = (rand() % 100) + 1;

    printf("=========================================\n");
    printf("    Welcome to the Number Guessing Game! \n");
    printf("=========================================\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");
    do 
    {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) 
        {
            printf("Invalid input! Please enter a valid integer.\n\n");
            while (getchar() != '\n'); 
            continue;
        }
        attempts++;
        if (guess > secret_number) 
        {
            printf("Too high! Try a smaller number.\n\n");
        } 
        else if (guess < secret_number) 
        {
            printf("Too low! Try a larger number.\n\n");
        } 
        else 
        {
            printf("\n🎉 Congratulations! You guessed it right!\n");
            printf("The secret number was %d.\n", secret_number);
            printf("It took you %d attempts to win.\n", attempts);
        }
    } 
    while (guess != secret_number);
    return 0;
}
