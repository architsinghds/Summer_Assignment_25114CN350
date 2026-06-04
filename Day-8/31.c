#include <stdio.h>
int main() 
{
    int n = 5;
    int i = 0;
    do {
        int j = 0;
        do {
            printf("%c ", j + 'A');
            j++;
        } while (j <= i);

        printf("\n");
        i++;
    } while (i < n);
    return 0;
}
