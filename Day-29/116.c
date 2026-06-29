#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100
#define NAME_LENGTH 50
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;
Item inventory[MAX_ITEMS];
int itemCount = 0;
void menu();
void addItem();
void viewInventory();
void updateStock();
void deleteItem();
int findItemIndex(int id);
int main() {
    int choice;
    do {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
void menu() {
    printf("\n=================================");
    printf("\n    INVENTORY MANAGEMENT SYSTEM  ");
    printf("\n=================================");
    printf("\n1. Add New Item");
    printf("\n2. View All Items");
    printf("\n3. Update Stock Quantity");
    printf("\n4. Delete Item");
    printf("\n5. Exit");
    printf("\n=================================\n");
}
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("\nError: Inventory capacity reached!\n");
        return;
    }
    Item newItem;
    printf("\nEnter Item ID (Integer): ");
    scanf("%d", &newItem.id);
    if (findItemIndex(newItem.id) != -1) {
        printf("Error: An item with ID %d already exists.\n", newItem.id);
        return;
    }
    printf("Enter Item Name: ");
    while (getchar() != '\n'); 
    fgets(newItem.name, NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; 
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    if (newItem.quantity < 0) {
        printf("Error: Quantity cannot be negative.\n");
        return;
    }
    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    if (newItem.price < 0) {
        printf("Error: Price cannot be negative.\n");
        return;
    }
    inventory[itemCount] = newItem;
    itemCount++;
    printf("\nItem '%s' added successfully!\n", newItem.name);
}
void viewInventory() {
    if (itemCount == 0) {
        printf("\nInventory is currently empty.\n");
        return;
    }
    printf("\n-------------------------------------------------------------");
    printf("\n %-10s | %-25s | %-10s | %-10s", "ID", "Name", "Quantity", "Price");
    printf("\n-------------------------------------------------------------");
    for (int i = 0; i < itemCount; i++) {
        printf("\n %-10d | %-25s | %-10d | $%-9.2f", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n-------------------------------------------------------------\n");
}
void updateStock() {
    int id, index, newQty;
    printf("\nEnter Item ID to update stock: ");
    scanf("%d", &id);
    index = findItemIndex(id);
    if (index == -1) {
        printf("Error: Item ID not found.\n");
        return;
    }
    printf("Current quantity of %s: %d\n", inventory[index].name, inventory[index].quantity);
    printf("Enter new total quantity: ");
    scanf("%d", &newQty);
    if (newQty < 0) {
        printf("Error: Quantity cannot be negative.\n");
        return;
    }
    inventory[index].quantity = newQty;
    printf("Stock updated successfully!\n");
}
void deleteItem() {
    int id, index;
    printf("\nEnter Item ID to delete: ");
    scanf("%d", &id);

    index = findItemIndex(id);
    if (index == -1) {
        printf("Error: Item ID not found.\n");
        return;
    }
    for (int i = index; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    itemCount--;
    printf("Item deleted successfully!\n");
}
int findItemIndex(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            return i; 
        }
    }
    return -1;
}
