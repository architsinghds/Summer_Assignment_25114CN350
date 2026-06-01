#include <stdio.h>

int main() 
{
    int num, i;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Prime Factors of %d are: ", num);
    if (num%2==0)
    {
        printf ("2");
        printf (" ");
    }

    for (i = 3; i <= num; i=i+2) 
    {
        if (num % i == 0 && num!=i) 
        {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
