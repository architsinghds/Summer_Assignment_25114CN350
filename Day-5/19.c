#include <stdio.h>

int main() {
    int num, i;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Prime Factors of %d are: ", num);

    for (i = 2; i <= num; ++i) {
        if (num % i == 0 && num!=i) 
        {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
