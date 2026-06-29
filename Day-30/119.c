#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

Employee empList[MAX_EMPLOYEES];
int empCount = 0;

void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n   EMPLOYEE MANAGEMENT SYSTEM");
        printf("\n====================================");
        printf("\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Delete Employee Record");
        printf("\n5. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid menu option entered.\n");
            clearInputBuffer();
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
                printf("\nExiting application. Goodbye!\n");
                exit(0);
            default:
                printf("\n[Error] Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addEmployee() {
    if (empCount >= MAX_EMPLOYEES) {
        printf("\n[Error] Database full! Cannot add more employees.\n");
        return;
    }

    Employee newEmp;
    printf("\nEnter Employee ID: ");
    if (scanf("%d", &newEmp.id) != 1) {
        printf("[Error] ID must be an integer numeric value.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < empCount; i++) {
        if (empList[i].id == newEmp.id) {
            printf("[Error] An employee with ID %d already exists.\n", newEmp.id);
            return;
        }
    }

    clearInputBuffer(); 

    printf("Enter Full Name: ");
    fgets(newEmp.name, sizeof(newEmp.name), stdin);
    newEmp.name[strcspn(newEmp.name, "\n")] = '\0'; 

    printf("Enter Designation: ");
    fgets(newEmp.designation, sizeof(newEmp.designation), stdin);
    newEmp.designation[strcspn(newEmp.designation, "\n")] = '\0';

    printf("Enter Salary: ");
    if (scanf("%f", &newEmp.salary) != 1 || newEmp.salary < 0) {
        printf("[Error] Invalid salary amount entered.\n");
        clearInputBuffer();
        return;
    }

    empList[empCount] = newEmp;
    empCount++;
    printf("\n[Success] Record added successfully!\n");
}

void displayEmployees() {
    if (empCount == 0) {
        printf("\n[Info] No records found in the database.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-10s", "ID", "Name", "Designation", "Salary");
    printf("\n------------------------------------------------------------------");
    for (int i = 0; i < empCount; i++) {
        printf("\n%-10d %-25s %-20s $%-9.2f", 
               empList[i].id, empList[i].name, empList[i].designation, empList[i].salary);
    }
    printf("\n------------------------------------------------------------------\n");
}

void searchEmployee() {
    if (empCount == 0) {
        printf("\n[Info] Database empty.\n");
        return;
    }

    int searchId;
    printf("\nEnter Employee ID to search: ");
    if (scanf("%d", &searchId) != 1) {
        printf("[Error] Invalid format.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < empCount; i++) {
        if (empList[i].id == searchId) {
            printf("\n--- Match Found ---");
            printf("\nID:          %d", empList[i].id);
            printf("\nName:        %s", empList[i].name);
            printf("\nDesignation: %s", empList[i].designation);
            printf("\nSalary:      $%.2f\n", empList[i].salary);
            return;
        }
    }
    printf("\n[Info] Employee with ID %d not found.\n", searchId);
}

void deleteEmployee() {
    if (empCount == 0) {
        printf("\n[Info] Database empty.\n");
        return;
    }

    int deleteId;
    printf("\nEnter Employee ID to delete: ");
    if (scanf("%d", &deleteId) != 1) {
        printf("[Error] Invalid format.\n");
        clearInputBuffer();
        return;
    }

    int indexFound = -1;
    for (int i = 0; i < empCount; i++) {
        if (empList[i].id == deleteId) {
            indexFound = i;
            break;
        }
    }

    if (indexFound == -1) {
        printf("\n[Info] Employee with ID %d does not exist.\n", deleteId);
        return;
    }

    for (int i = indexFound; i < empCount - 1; i++) {
        empList[i] = empList[i + 1];
    }
    empCount--;
    printf("\n[Success] Record deleted successfully!\n");
}
