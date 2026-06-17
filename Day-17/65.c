#include <stdio.h>
int main() 
{
    int arr1[50], arr2[50], merged[100];
    int size1, size2, i;
    printf("Enter size for first and second arrays: ");
    scanf("%d %d", &size1, &size2);
    printf("Enter elements for array 1: ");
    for (i = 0; i < size1; i++) 
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter elements for array 2: ");
    for (i = 0; i < size2; i++) 
    {
        scanf("%d", &arr2[i]);
    }
    for (i = 0; i < size1; i++) 
    {
        merged[i] = arr1[i]; 
    }
    for (i = 0; i < size2; i++) 
    {
        merged[size1 + i] = arr2[i];
    }
    printf("Merged array: ");
    for (i = 0; i < size1 + size2; i++) 
    {
        printf("%d ", merged[i]);
    }
    return 0;
}
