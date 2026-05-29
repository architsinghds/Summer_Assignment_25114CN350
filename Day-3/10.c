#include <stdio.h>

int main() 
{
    int l, u, i, temp, j;

    printf("Enter the range of numbers\n");
    printf("Lower range: ");
    scanf("%d", &l);
    printf("Upper Range: ");
    scanf("%d", &u);

    
    if (l < 2) 
    {
        l = 2;
    }

    for (i = l; i <= u; i++) 
    {
        temp=1;
        for (j = 2; j <= (i / 2); j++) {
            if (i % j == 0) 
            { 
                temp = 0;
                break;
            }
        }

        if (temp == 1) {
            printf("%d\t", i);
        }
    }

    return 0;
}
