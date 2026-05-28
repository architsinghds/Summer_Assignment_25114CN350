#include<stdio.h>
int main()
{int num,tab;
    printf("Enter the number to finds its table:");
    scanf("%d",&num);
    for(int i=1;i<=10;i++)
    {
    tab=num*i;
    printf("%d\n",tab);
    }
    return 0;
}
