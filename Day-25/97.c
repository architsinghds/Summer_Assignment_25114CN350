#include<stdio.h>
void merge(int arr1[], int arr2[], int n1, int n2, int merged[]) 
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) 
    {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    while (i < n1)
        merged[k++] = arr1[i++];
    while (j < n2)
        merged[k++] = arr2[j++];
}
int main() 
{
    int arr1[50], arr2[50], merged[100];
    int n1, n2, i;
    printf("Enter number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter sorted elements of the first array: ");
    for (i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);
    printf("Enter number of elements in the second array: ");
    scanf("%d", &n2);
    printf("Enter sorted elements of the second array: ");
    for (i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);
    merge(arr1, arr2, n1, n2, merged);
    printf("Merged sorted array: ");
    for (i = 0; i < n1 + n2; i++)
        printf("%d ", merged[i]);
    return 0;
}
