#include <stdio.h>

int main() {
    int a[10][10], b[10][10], mul[10][10];
    int r1, c1, r2, c2, i, j, k;

    printf("Enter rows and columns for First matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for Second matrix: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) {
        printf("\nError! Column of first matrix must equal row of second matrix.\n");
        return 0;
    }

    printf("\nEnter elements of First matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of Second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("Enter element b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            mul[i][j] = 0; 
            
            for (k = 0; k < c1; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nResultant Multiplication Matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", mul[i][j]);
        }
        printf("\n");
    }

    return 0;
}
