#include <stdio.h>
int main() 
{
    int rows;
    printf ("Enter No,of Rows:");
    scanf ("%d",&rows);
    for (int i = rows; i >= 1; i--) 
    {
        for (int j = 0; j < rows - i; j++) 
        {
            printf(" ");
        }
        for (int k = 0; k < (2 * i - 1); k++) 
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

