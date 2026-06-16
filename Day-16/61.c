#include <stdio.h>
int main() 
{
    int n, i;
    int actual_sum = 0;
    int expected_sum, missing_number;
    printf("Enter total numbers in sequence: ");
    scanf("%d", &n);
    int arr[n - 1]; 
    printf("Enter the %d elements of the array:\n", n - 1);
    for (i = 0; i < n - 1; i++) 
    {
        scanf("%d", &arr[i]);
        actual_sum += arr[i]; 
    }
    expected_sum = (n * (n + 1)) / 2;
    missing_number = expected_sum - actual_sum;
    printf("The missing number is: %d\n", missing_number);
    return 0;
}
