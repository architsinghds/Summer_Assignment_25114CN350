#include <stdio.h>
void moveZeroesToEnd(int arr[], int n) 
{
    int j = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] != 0) 
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}
int main() 
{
    int arr[] = {1, 0, 3, 0, 12, 0, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]); 
    printf("Original array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    moveZeroesToEnd(arr, n);
    printf("Modified array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
