#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
void createArray(int arr[], int *size);
void displayArray(const int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
int searchElement(const int arr[], int size, int target);
int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, target, index;
    do {
        printf("\n====================================");
        printf("\n      ARRAY OPERATIONS SYSTEM       ");
        printf("\n====================================");
        printf("\n 1. Create/Initialize Array");
        printf("\n 2. Display Array Elements");
        printf("\n 3. Insert Element at a Position");
        printf("\n 4. Delete Element from a Position");
        printf("\n 5. Search for an Element");
        printf("\n 6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("\nError: Invalid character input!\n");
            break;
        }
        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                if (size == 0) {
                    printf("\nError: Array is empty! Nothing to search.\n");
                } else {
                    printf("\nEnter the element to search for: ");
                    scanf("%d", &target);
                    index = searchElement(arr, size, target);
                    if (index != -1) {
                        printf("\nSuccess: Element %d found at index %d (Position %d).\n", target, index, index + 1);
                    } else {
                        printf("\nResult: Element %d not found in the array.\n", target);
                    }
                }
                break;
            case 6:
                printf("\nExiting system. Have a nice day!\n");
                break;
            default:
                printf("\nError: Invalid option chosen! Please choose between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
void createArray(int arr[], int *size) {
    int n;
    printf("\nEnter total number of elements (Max %d): ", MAX_SIZE);
    scanf("%d", &n);
    if (n < 0 || n > MAX_SIZE) {
        printf("\nError: Invalid size! Cannot create an array of size %d.\n", n);
        return;
    }
    *size = n;
    printf("Enter %d integers:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nSuccess: Array created with %d elements!\n", *size);
}
void displayArray(const int arr[], int size) {
    if (size == 0) {
        printf("\nNotification: The array is currently empty.\n");
        return;
    }
    printf("\n--- Current Array Elements ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n------------------------------\n");
}
void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("\nError: Array Overflow! Cannot insert more elements.\n");
        return;
    }
    int pos, element;
    printf("\nEnter the position (1 to %d) to insert element: ", *size + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > *size + 1) {
        printf("\nError: Invalid position choice!\n");
        return;
    }
    printf("Enter integer value to insert: ");
    scanf("%d", &element);
    for (int i = *size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    (*size)++; 
    printf("\nSuccess: Element inserted successfully!\n");
}
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\nError: Array Underflow! No items available to delete.\n");
        return;
    }
    int pos;
    printf("\nEnter the position (1 to %d) of the element to delete: ", *size);
    scanf("%d", &pos);
    if (pos < 1 || pos > *size) {
        printf("\nError: Invalid position choice!\n");
        return;
    }
    int deletedItem = arr[pos - 1];
    for (int i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("\nSuccess: Element %d deleted from position %d.\n", deletedItem, pos);
}
int searchElement(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
