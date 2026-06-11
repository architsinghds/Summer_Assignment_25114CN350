#include <stdio.h>
int findMax(int num1, int num2);
int main() 
{
    int a, b, maxVal;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    maxVal = findMax(a, b);
    printf("The maximum number is: %d\n", maxVal);
    return 0;
}
int findMax(int num1, int num2) 
{
    return (num1 > num2) ? num1 : num2;
}
