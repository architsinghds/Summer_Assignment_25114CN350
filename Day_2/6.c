#include<stdio.h>
int main ()
{
    int num, rev=0,rem;
    printf("Enter the number:");
    scanf("%d",&num);
    
    printf("The number is = %d\n",num);
    while(num!=0)
    {
        rem=num%10;
        rev=rev*10+rem;
        num = num / 10;
    }
 
    
    printf("Reverse of the given number is : %d\n",rev);
 
    return 0;
}
