#include <stdio.h>
int main() 
{
    int num, i, max;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num%2==0)
    {
        max=2;
        num=num/2;
    }

    for (i = 3; i*i <= num; i=i+2) 
    {
        if (num % i == 0) 
        {
            max=i;
        }
    }

    printf("Largest prime factor is %d",max);
    return 0;
}
