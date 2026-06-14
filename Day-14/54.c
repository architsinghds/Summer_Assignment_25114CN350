#include <stdio.h>
int main() 
{
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];
    int visited[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }
    for (int i = 0; i < size; i++) 
    {
        if (visited[i] == 1) 
        {
            continue;
        }
        int count = 1; 
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                count++;
                visited[j] = 1; 
            }
        }
        printf("Element %d occurs %d time(s)\n", arr[i], count);
    }
    return 0;
}
