#include <stdio.h>

int main() {
    int n, i, j;
    int a[10][10];
    int is_symmetric = 1; 

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
        for (j = i + 1; j < n; j++) { 
            if (a[i][j] != a[j][i]) {
                is_symmetric = 0; 
            }
        }
        if (!is_symmetric) {
            break;
        }
    }

    if (is_symmetric) {
        printf("\nThe matrix is a Symmetric Matrix.\n");
    } else {
        printf("\nThe matrix is NOT a Symmetric Matrix.\n");
    }

    return 0;
}

