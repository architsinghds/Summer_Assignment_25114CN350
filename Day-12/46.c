#include <stdio.h>
#include <math.h>
int isArmstrong(int num);
int main() 
{
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    if (isArmstrong(number)) 
    {
        printf("%d is an Armstrong number.\n", number);
    } 
    else 
    {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}
int isArmstrong(int num) 
{
    int originalNum, remainder, originalNumDigits;
    int digits = 0;
    double sum = 0.0;
    originalNum = num;
    originalNumDigits = num;
    while (originalNumDigits != 0) 
    {
        originalNumDigits /= 10;
        digits++;
    }
    while (originalNum != 0) 
    {
        remainder = originalNum % 10;
        sum += pow(remainder, digits);
        originalNum /= 10;
    }
    if ((int)round(sum) == num) 
    {
        return 1; 
    } 
    else 
    {
        return 0; 
    }
}
