#include <stdio.h>

int main() {
    int r, c, i, j;
    int a[100][100];

    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);

    printf("\nEnter elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n--- Row-wise Sum Results ---\n");
    
    for (i = 0; i < r; i++) {
        int row_sum = 0; 
        
        for (j = 0; j < c; j++) {
            row_sum += a[i][j];
        }
        
        printf("Sum of Row %d = %d\n", i + 1, row_sum);
    }

    return 0;
}
