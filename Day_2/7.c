#include<stdio.h>
int main ()
{
    int num, pro=1,rem;
    printf("Enter the number:");
    scanf("%d",&num);
    
    printf("The number is = %d\n",num);
    while(num!=0)
    {
        rem=num%10;
        pro=pro*rem;
        num = num / 10;
    }
 
    
    printf("The Product of the digits of the given number is : %d\n",pro);
 
    return 0;
}
