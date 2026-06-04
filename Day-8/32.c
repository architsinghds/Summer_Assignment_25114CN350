#include <stdio.h>

int main() 
{
    int n = 5;
    int i = 0;
    while (i < n) 
    {
        int j = 0;
        while (j <= i) 
        {
            printf("%d ", i + 1);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
