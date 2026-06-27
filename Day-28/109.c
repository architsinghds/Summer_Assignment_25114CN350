#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOKS 100
typedef struct {
    int id;
    char title[100];
    char author[50];
    int isAvailable; 
} Book;
void addBook(Book library[], int *bookCount);
void displayBooks(const Book library[], int bookCount);
void searchBook(const Book library[], int bookCount);
void issueBook(Book library[], int bookCount);
void returnBook(Book library[], int bookCount);
void clearInputBuffer();
int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;
    while (1) {
        printf("\n=================================");
        printf("\n=== Library Management System ===");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                issueBook(library, bookCount);
                break;
            case 5:
                returnBook(library, bookCount);
                break;
            case 6:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}
void addBook(Book library[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("\nLibrary capacity reached! Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("\nEnter Unique Book ID (Integer): ");
    if (scanf("%d", &newBook.id) != 1) {
        printf("Invalid ID format!\n");
        clearInputBuffer();
        return;
    }
    for (int i = 0; i < *bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("\nError: A book with ID %d already exists!\n", newBook.id);
            return;
        }
    }
    clearInputBuffer();
    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; 
    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';
    newBook.isAvailable = 1; 
    library[*bookCount] = newBook;
    (*bookCount)++;
    printf("\nBook added successfully!\n");
}
void displayBooks(const Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }
    printf("\n%-10s %-40s %-30s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n-------------------------------------------------------------------------------------------------");
    for (int i = 0; i < bookCount; i++) {
        printf("\n%-10d %-40s %-30s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].isAvailable ? "Available" : "Issued");
    }
    printf("\n");
}
void searchBook(const Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nNo books to search.\n");
        return;
    }
    int searchId;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\nBook Found!");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].isAvailable ? "Available" : "Issued");
            return;
        }
    }
    printf("\nBook with ID %d not found.\n", searchId);
}
void issueBook(Book library[], int bookCount) {
    int issueId;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issueId);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == issueId) {
            if (library[i].isAvailable) {
                library[i].isAvailable = 0;
                printf("\nBook '%s' has been successfully issued.\n", library[i].title);
            } else {
                printf("\nSorry, this book is already issued to someone else.\n");
            }
            return;
        }
    }
    printf("\nBook ID not found.\n");
}
void returnBook(Book library[], int bookCount) {
    int returnId;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &returnId);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == returnId) {
            if (!library[i].isAvailable) {
                library[i].isAvailable = 1;
                printf("\nBook '%s' has been successfully returned to the inventory.\n", library[i].title);
            } else {
                printf("\nThis book is already marked as available in the library.\n");
            }
            return;
        }
    }
    printf("\nBook ID not found.\n");
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
