#include<stdio.h>
int main ()
{
    int num,rem, orignum, rev=0;
    printf("Enter the number:");
    scanf("%d",&num);
    
    printf("The entered number is = %d\n",num);
    orignum=num;
    while(num!=0)
    {
        rem=num%10;
        rev=rev*10+rem;
        num = num / 10;
    }
    if (orignum==rev)
    {
        printf("The entered number is palindrome");
    }
    else
    {
        printf("The entered number is not palindrome");
    }
    return 0;
}
