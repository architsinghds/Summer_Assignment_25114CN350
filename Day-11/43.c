#include <stdio.h>
int isPrime(int n) 
{
    if (n <= 1) 
    {
        return 0;
    }
    if (n == 2) 
    {
        return 1;
    }
    if (n % 2 == 0) 
    {
        return 0;
    }
    for (int i = 3; i * i <= n; i += 2) 
    {
        if (n % i == 0) 
        {
            return 0;
        }
    }
    
    return 1;
}
int main() 
{
    int num;
    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1) 
    {
        printf("Invalid input.\n");
        return 1;
    }
    if (isPrime(num)) 
    {
        printf("%d is a prime number.\n", num);
    } 
    else 
    {
        printf("%d is not a prime number.\n", num);
    }
    return 0;
}
