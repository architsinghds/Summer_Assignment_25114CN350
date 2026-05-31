#include <stdio.h>

int main() {
    int terms;
 
    int first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    if (scanf("%d", &terms) != 1 || terms <= 0) 
    {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printf("Fibonacci Series: ");

    for (int i = 1; i <= terms; ++i) 
    {
        printf("%d", first);
        
        if (i < terms) 
        {
            printf(" ");
        }

       
        next = first + second;
        first = second;
        second = next;
    }

    printf("\n");
    return 0;
}
