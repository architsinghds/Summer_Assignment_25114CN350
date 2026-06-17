#include <stdio.h>
#include <stdbool.h>
void findIntersection(int arr1[], int size1, int arr2[], int size2) 
{
    int intersect[100]; 
    int k = 0;          
    printf("Intersection: ");
    for (int i = 0; i < size1; i++) 
    {
        bool foundInArr2 = false;
        for (int j = 0; j < size2; j++) 
        {
            if (arr1[i] == arr2[j]) 
            {
                foundInArr2 = true;
                break;
            }
        }
        if (foundInArr2) 
        {
            bool isDuplicate = false;
            for (int m = 0; m < k; m++) 
            {
                if (arr1[i] == intersect[m]) 
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) 
            {
                intersect[k] = arr1[i];
                k++;
            }
        }
    }
    if (k == 0) 
    {
        printf("No common elements found.");
    } 
    else 
    {
        for (int i = 0; i < k; i++) 
        {
            printf("%d ", intersect[i]);
        }
    }
    printf("\n");
}
int main() 
{
    int array1[] = {4, 9, 5, 4, 2, 7};
    int array2[] = {9, 4, 9, 8, 4, 1};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    printf("Array 1: ");
    for(int i = 0; i < size1; i++) 
    {
        printf("%d ", array1[i]);
    }
    printf("\nArray 2: ");
    for(int i = 0; i < size2; i++) 
    {
        printf("%d ", array2[i]);
    }
    printf("\n\n");
    findIntersection(array1, size1, array2, size2);
    return 0;
}
