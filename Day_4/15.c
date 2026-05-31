#include <stdio.h>
#include <math.h>

int main() 
{
    int num, originalNum, remainder, count = 0, result = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;
    while (originalNum != 0) 
    {
        originalNum /= 10;
        count++;
    }

    originalNum = num;

    while (originalNum != 0) 
    {
        remainder = originalNum % 10;

        result += round(pow(remainder, count)); 
        
        originalNum /= 10;
    }

    
    if ((int)result == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
