#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 40

void displayMenu();
void addStudent(int rollNums[], char names[][NAME_LENGTH], float marks[], int *count);
void displayStudents(const int rollNums[], const char names[][NAME_LENGTH], const float marks[], int count);
void searchStudent(const int rollNums[], const char names[][NAME_LENGTH], const float marks[], int count);
void calculateAverage(const float marks[], int count);

int main() {
    int studentRollNums[MAX_STUDENTS];
    char studentNames[MAX_STUDENTS][NAME_LENGTH]; 
    float studentMarks[MAX_STUDENTS];
    
    int currentStudentCount = 0;
    int userChoice;

    printf("=== Welcome to the Student Management System Mini-Project ===\n");

    while (1) {
        displayMenu();
        printf("Enter your selection (1-5): ");
        if (scanf("%d", &userChoice) != 1) {
            printf("Invalid system input. Exiting.\n");
            break;
        }

        while (getchar() != '\n'); 

        switch (userChoice) {
            case 1:
                addStudent(studentRollNums, studentNames, studentMarks, &currentStudentCount);
                break;
            case 2:
                displayStudents(studentRollNums, studentNames, studentMarks, currentStudentCount);
                break;
            case 3:
                searchStudent(studentRollNums, studentNames, studentMarks, currentStudentCount);
                break;
            case 4:
                calculateAverage(studentMarks, currentStudentCount);
                break;
            case 5:
                printf("\nThank you for using the program! Goodbye.\n");
                return 0;
            default:
                printf("Error: Invalid choice. Please pick an option from 1 to 5.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n-------------------------------------\n");
    printf("            SYSTEM MENU              \n");
    printf("-------------------------------------\n");
    printf("1. Add a New Student Record\n");
    printf("2. Display All Student Records\n");
    printf("3. Search a Student by Exact Name\n");
    printf("4. Show Class Average Grade\n");
    printf("5. Exit System\n");
    printf("-------------------------------------\n");
}

void addStudent(int rollNums[], char names[][NAME_LENGTH], float marks[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nError: System database is full! Cannot add more records.\n");
        return;
    }

    printf("\n--- Enter Student Details ---\n");
    
    printf("Enter Roll Number (Integer): ");
    scanf("%d", &rollNums[*count]);
    while (getchar() != '\n'); 

    printf("Enter Full Name: ");
    fgets(names[*count], NAME_LENGTH, stdin);
    names[*count][strcspn(names[*count], "\n")] = '\0';

    printf("Enter Marks (0.00 - 100.00): ");
    scanf("%f", &marks[*count]);
    
    (*count)++;
    printf("Success: Student record added cleanly.\n");
}

void displayStudents(const int rollNums[], const char names[][NAME_LENGTH], const float marks[], int count) {
    if (count == 0) {
        printf("\nNotice: The active student database is empty.\n");
        return;
    }

    printf("\n=======================================================\n");
    printf("%-10s | %-25s | %-10s\n", "Roll No", "Student Name", "Marks");
    printf("=======================================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10d | %-25s | %-10.2f\n", rollNums[i], names[i], marks[i]);
    }
    printf("=======================================================\n");
}

void searchStudent(const int rollNums[], const char names[][NAME_LENGTH], const float marks[], int count) {
    if (count == 0) {
        printf("\nNotice: Database is empty. Nothing to search.\n");
        return;
    }

    char queryName[NAME_LENGTH];
    int recordFound = 0;

    printf("\nEnter exact student name to look up: ");
    fgets(queryName, NAME_LENGTH, stdin);
    queryName[strcspn(queryName, "\n")] = '\0'; 

    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], queryName) == 0) {
            printf("\n Record Found at System Index [%d]!\n", i);
            printf("Roll Number: %d\n", rollNums[i]);
            printf("Full Name:   %s\n", names[i]);
            printf("Final Marks: %.2f\n", marks[i]);
            recordFound = 1;
            break; 
        }
    }

    if (!recordFound) {
        printf("\nResult: No student matches the name \"%s\".\n", queryName);
    }
}

void calculateAverage(const float marks[], int count) {
    if (count == 0) {
        printf("\nNotice: Database contains no score metrics.\n");
        return;
    }

    float accumulationSum = 0.0;
    for (int i = 0; i < count; i++) {
        accumulationSum += marks[i];
    }

    float finalAverage = accumulationSum / count;
    printf("\n--- Grade Metrics Report ---\n");
    printf("Total Enrolled Students: %d\n", count);
    printf("Cumulative Class Average Score: %.2f\n", finalAverage);
}
