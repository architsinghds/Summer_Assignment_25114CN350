#include<stdio.h>
int main()
{
    int num, i, m, temp=0;
    printf ("Enter the number:");
    scanf ("%d",&num);
    printf("The entered numner is %d",num);
    printf("\n");
    m=num/2;
    for (i=2; i<=m; i++)
    {
        if (num%i==0)
        {
            temp=1;
            break;
        }

    }
    if (temp==0)
    {
        printf("The Entered Number is prime number.");
    }
    else
    {
        printf("The Entered Number is composite number.");
    }
    return 0;
}
