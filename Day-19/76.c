#include <stdio.h>

int main() {
    int n, i, j;
    int a[100][100];
    int primary_sum = 0, secondary_sum = 0;

    printf("Enter the size of the square matrix (N x N): ");
    scanf("%d", &n);

    printf("\nEnter elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

 
    for (i = 0; i < n; i++) {
        primary_sum += a[i][i];              
        secondary_sum += a[i][n - i - 1];     
    }

    printf("\nPrimary Diagonal Sum   = %d", primary_sum);
    printf("\nSecondary Diagonal Sum = %d\n", secondary_sum);

    return 0;
}
