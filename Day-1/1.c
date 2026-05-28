#include<stdio.h>
int main()
{int n,sum=0;
    printf("Enter the last number up to which you find the sum:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    sum+=i;
    }
    printf("Here is your sum=%d",sum);
    return 0;
}
