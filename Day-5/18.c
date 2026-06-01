#include <stdio.h>

int main() {
    int num, originalNum, rem, sum = 0;
    long fact;

    printf("Enter an integer: ");
    scanf("%d", &num);
    
    originalNum = num;

  
    for (int temp = num; temp > 0; temp /= 10) 
    {
        rem = temp % 10; 
        fact = 1;        

        for (int i = 1; i <= rem; i++) 
        {
            fact *= i;
        }

        sum += fact;
    }

    if (sum == originalNum) 
    {
        printf("%d is a Strong Number.\n", originalNum);
    } 
    else 
    {
        printf("%d is NOT a Strong Number.\n", originalNum);
    }

    return 0;
}
