#include <stdio.h>
int findSum(int num1, int num2);
int main() 
{
    int a, b, result;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    result = findSum(a, b);
    printf("The sum of %d and %d is: %d\n", a, b, result);
    return 0;
}
int findSum(int num1, int num2) 
{
    return num1 + num2;
}
