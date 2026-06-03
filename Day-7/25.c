#include <stdio.h>
long int fact(int n); 
int main() 
{
    int num;
    long int j; 
    printf("Enter the number: ");
    scanf("%d", &num);
    
    j = fact(num);
    
    printf("Factorial of number = %ld\n", j); 
    return 0;
}

long int fact(int n) 
{ 
    if (n == 0) 
    { 
        return 1;
    } 
    else 
    {
        return (n * fact(n - 1));
    }
}
