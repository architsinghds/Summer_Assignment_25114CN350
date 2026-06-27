#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "contacts.txt"
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;
void addContact();
void listContacts();
void searchContact();
void deleteContact();
void clearInputBuffer();
int main() {
    int choice;
    while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Contact\n");
        printf("2. List All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Delete a Contact\n");
        printf("5. Exit Application\n");
        printf("=================================\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); 
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    }
    return 0;
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void addContact() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    Contact newContact;
    printf("\nEnter Name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; 
    printf("Enter Phone Number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';
    printf("Enter Email Address: ");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';
    fprintf(file, "%s|%s|%s\n", newContact.name, newContact.phone, newContact.email);
    fclose(file);
    printf("\nSuccess: Contact added successfully!\n");
}
void listContacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo saved contacts found or file does not exist yet.\n");
        return;
    }
    Contact current;
    char line[150];
    int count = 1;
    printf("\n%-5s %-25s %-15s %-30s\n", "S.No", "Name", "Phone", "Email");
    printf("----------------------------------------------------------------------------\n");
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, "|");
        if (token) strcpy(current.name, token);
        token = strtok(NULL, "|");
        if (token) strcpy(current.phone, token);
        token = strtok(NULL, "\n");
        if (token) strcpy(current.email, token);
        printf("%-5d %-25s %-15s %-30s\n", count++, current.name, current.phone, current.email);
    }
    if (count == 1) {
        printf("The contact directory is currently empty.\n");
    }
    fclose(file);
}
void searchContact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo saved contacts found to search.\n");
        return;
    }
    char searchQuery[50];
    char line[150];
    Contact current;
    int found = 0;
    printf("\nEnter the Name to search for: ");
    fgets(searchQuery, sizeof(searchQuery), stdin);
    searchQuery[strcspn(searchQuery, "\n")] = '\0';
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, "|");
        if (token) strcpy(current.name, token);
        token = strtok(NULL, "|");
        if (token) strcpy(current.phone, token);
        token = strtok(NULL, "\n");
        if (token) strcpy(current.email, token);
        if (strstr(current.name, searchQuery) != NULL) {
            if (!found) {
                printf("\nMatch Found:\n");
                printf("----------------------------------------\n");
            }
            printf("Name:  %s\n", current.name);
            printf("Phone: %s\n", current.phone);
            printf("Email: %s\n\n", current.email);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo matching contact found for '%s'.\n", searchQuery);
    }
    fclose(file);
}
void deleteContact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo saved contacts found to delete.\n");
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("System Error: Failed to open temporary file workspace.\n");
        fclose(file);
        return;
    }
    char targetName[50];
    char line[150];
    Contact current;
    int deleted = 0;
    printf("\nEnter the exact Name of the contact to delete: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';
    while (fgets(line, sizeof(line), file)) {
        char lineCopy[150];
        strcpy(lineCopy, line);
        char *token = strtok(line, "|");
        if (token) strcpy(current.name, token);
        if (strcmp(current.name, targetName) == 0) {
            deleted = 1;
            continue; 
        }
        fprintf(tempFile, "%s", lineCopy);
    }

    fclose(file);
    fclose(tempFile);

    if (deleted) {
        remove(FILE_NAME);            
        rename("temp.txt", FILE_NAME); 
        printf("\nSuccess: Contact record removed permanently.\n");
    } else {
        remove("temp.txt");            
        printf("\nNo matching contact found. Deletion cancelled.\n");
    }
}
