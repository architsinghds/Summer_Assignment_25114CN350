#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "employees.txt"
struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Employee Record\n");
        printf("2. Display All Employee Records\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee Record\n");
        printf("5. Exit System\n");
        printf("Enter your selection (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid data input type. Please try again.\n");
            clearBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("Exiting application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid selection! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}
void clearBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void addEmployee() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) 
    {
        printf("Error opening database file!\n");
        return;
    }
    struct Employee emp;
    printf("\nEnter Employee ID (integer): ");
    scanf("%d", &emp.id);
    clearBuffer();
    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0'; 
    printf("Enter Department Name: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = '\0';
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);
    fprintf(file, "%d,%s,%s,%.2f\n", emp.id, emp.name, emp.department, emp.salary);
    fclose(file);
    printf("Employee record created and saved successfully!\n");
}
void displayEmployees() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo data found. Add employee records first!\n");
        return;
    }
    struct Employee emp;
    printf("\n---------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("---------------------------------------------------------------\n");
    while (fscanf(file, "%d,%[^,],%[^,],%f\n", &emp.id, emp.name, emp.department, &emp.salary) != EOF) {
        printf("%-10d %-20s %-20s $%-10.2f\n", emp.id, emp.name, emp.department, emp.salary);
    }
    printf("---------------------------------------------------------------\n");
    fclose(file);
}
void searchEmployee() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo data found in the records database file!\n");
        return;
    }
    int searchId;
    int recordFound = 0;
    struct Employee emp;
    printf("\nEnter Employee ID to look up: ");
    scanf("%d", &searchId);

    while (fscanf(file, "%d,%[^,],%[^,],%f\n", &emp.id, emp.name, emp.department, &emp.salary) != EOF) {
        if (emp.id == searchId) {
            printf("\nEmployee Profile Found:\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Department: %s\n", emp.department);
            printf("Salary: $%.2f\n", emp.salary);
            recordFound = 1;
            break;
        }
    }
    if (!recordFound) 
    {
        printf("Employee entry with ID %d was not found.\n", searchId);
    }
    fclose(file);
}
void deleteEmployee() 
{
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo database files found to manipulate entries.\n");
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) 
    {
        printf("Internal memory handling error writing temporary file.\n");
        fclose(file);
        return;
    }
    int targetId;
    int recordFound = 0;
    struct Employee emp;
    printf("\nEnter the Employee ID you wish to completely delete: ");
    scanf("%d", &targetId);
    while (fscanf(file, "%d,%[^,],%[^,],%f\n", &emp.id, emp.name, emp.department, &emp.salary) != EOF) {
        if (emp.id == targetId) {
            recordFound = 1; 
        } 
        else 
        {
            fprintf(tempFile, "%d,%s,%s,%.2f\n", emp.id, emp.name, emp.department, emp.salary);
        }
    }
    fclose(file);
    fclose(tempFile);
    if (recordFound) 
    {
        remove(FILE_NAME);       
        rename("temp.txt", FILE_NAME); 
        printf("Employee row deleted completely.\n");
    } 
    else 
    {
        remove("temp.txt"); 
        printf("Employee with ID %d not found.\n", targetId);
    }
}
