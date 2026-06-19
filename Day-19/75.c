#include <stdio.h>

int main() {
    int r, c, i, j;
    int a[100][100], transpose[100][100];

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

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            transpose[j][i] = a[i][j]; 
        }
    }

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("\nTransposed Matrix:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
