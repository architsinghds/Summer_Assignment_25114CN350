#include <stdio.h>
int main() 
{
    int n, i, search, first, last, middle;
    int flag = 0; 
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int array[n]; 
    printf("Enter %d integers in ascending order:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &array[i]);
    }
    printf("Enter value to find: ");
    scanf("%d", &search);
    first = 0;
    last = n - 1;
    while (first <= last) 
    {
        middle = first + (last - first) / 2; 
        if (array[middle] < search) 
        {
            first = middle + 1; 
        } 
        else if (array[middle] == search) 
        {
            printf("%d found at index %d (position %d).\n", search, middle, middle + 1);
            flag = 1; 
            break;    
        } 
        else 
        {
            last = middle - 1; 
        }
    }
    if (flag == 0) 
    {
        printf("Not found! %d isn't present in the list.\n", search);
    }
    return 0;
}
