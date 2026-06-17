#include <stdio.h>
int main() 
{
    int array1[] = {1, 2, 3, 4, 5, 6};
    int array2[] = {4, 5, 6, 7, 8, 9};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int common[size1]; 
    int k = 0;
    for (int i = 0; i < size1; i++) 
    {
        for (int j = 0; j < size2; j++) 
        {
            if (array1[i] == array2[j]) 
            {
                int alreadyExists = 0;
                for (int x = 0; x < k; x++) 
                {
                    if (array1[i] == common[x]) 
                    {
                        alreadyExists = 1;
                        break;
                    }
                }
                if (!alreadyExists) 
                {
                    common[k] = array1[i];
                    k++;
                }
                break; 
            }
        }
    }
    if (k == 0) 
    {
        printf("No common elements found.\n");
    } 
    else 
    {
        printf("Common elements are: ");
        for (int i = 0; i < k; i++) 
        {
            printf("%d ", common[i]);
        }
        printf("\n");
    }
    return 0;
}
