#include <stdio.h>

int main() 
{
    long long binary_num, temp;
    int decimal_num = 0, base = 1, rem;

    printf("Enter a binary number (using only 0 and 1): ");
    scanf("%lld", &binary_num);

    temp = binary_num;

    while (temp > 0) 
    {
        rem = temp % 10;              
        decimal_num += rem * base;    
        base = base * 2;              
        temp = temp / 10;             
    }


    printf("Binary: %lld\n", binary_num);
    printf("Decimal equivalent: %d\n", decimal_num);

    return 0;
}
