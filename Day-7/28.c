#include <stdio.h>
int reverseNumber(int num, int reversed) 
{
    if (num == 0) 
    {
        return reversed;
    }
    
    reversed = (reversed * 10) + (num % 10);
    return reverseNumber(num / 10, reversed);
}

int main() 
{
    int number;
    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) 
    {
        printf("Invalid input.\n");
        return 1;
    }
    int isNegative = (number < 0);
    int lookupNumber = isNegative ? -number : number;
    int result = reverseNumber(lookupNumber, 0);
    if (isNegative) 
    {
        result = -result;
    }

    printf("Reversed number: %d\n", result);
    return 0;
}
