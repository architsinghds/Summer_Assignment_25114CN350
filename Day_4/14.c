#include<stdio.h>
int main() 
{

    int a = 0, b = 1, next, i ,n;
    printf ("Enter the term you want to find:");
    scanf ("%d",&n);
    if (n == 0 || n == 1)
    {
        printf("fib(%d) : %d",n, n);
        return 0;
    }

    for (i = 2; i <= n; ++i) 
    {
        next= a + b;
        a = b;
        b = next;
    }
    printf("fib(%d) : %d",n, next);
    
    return 0;
}
