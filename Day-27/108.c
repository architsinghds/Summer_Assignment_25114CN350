#include <stdio.h>
#include <string.h>
#define NUM_SUBJECTS 5
struct Student 
{
    int rollNumber;
    char name[50];
    int marks[NUM_SUBJECTS];
    int totalMarks;
    float percentage;
    char grade[3];
};
const char *subjectNames[NUM_SUBJECTS] = 
{
    "Mathematics",
    "Physics",
    "Chemistry",
    "English",
    "Computer Science"
};
void inputStudentData(struct Student *s);
void calculateResults(struct Student *s);
void displayMarksheet(const struct Student *s);
int main() 
{
    struct Student student;
    printf("==================================================\n");
    printf("        STUDENT MARKSHEET GENERATION SYSTEM       \n");
    printf("==================================================\n");
    inputStudentData(&student);
    calculateResults(&student);
    displayMarksheet(&student);
    return 0;
}
void inputStudentData(struct Student *s) 
{
    printf("\nEnter Roll Number: ");
    scanf("%d", &s->rollNumber);
    while (getchar() != '\n'); 
    printf("Enter Student Name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';
    printf("\n--- Enter Marks (Out of 100) ---\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        do {
            printf("%-18s: ", subjectNames[i]);
            scanf("%d", &s->marks[i]);
            
            if (s->marks[i] < 0 || s->marks[i] > 100) 
            {
                printf("Error: Marks must be between 0 and 100. Please re-enter.\n");
            }
        } while (s->marks[i] < 0 || s->marks[i] > 100);
    }
}
void calculateResults(struct Student *s) 
{
    s->totalMarks = 0;
    int hasFailedSubject = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) 
    {
        s->totalMarks += s->marks[i];
        if (s->marks[i] < 40) {
            hasFailedSubject = 1; 
        }
    }
    s->percentage = (float)s->totalMarks / NUM_SUBJECTS;
    if (hasFailedSubject) 
    {
        strcpy(s->grade, "F");
    } 
    else if (s->percentage >= 90.0) 
    {
        strcpy(s->grade, "A+");
    } 
    else if (s->percentage >= 80.0) 
    {
        strcpy(s->grade, "A");
    } 
    else if (s->percentage >= 70.0) 
    {
        strcpy(s->grade, "B");
    } 
    else if (s->percentage >= 60.0) 
    {
        strcpy(s->grade, "C");
    } 
    else if (s->percentage >= 50.0) 
    {
        strcpy(s->grade, "D");
    } 
    else 
    {
        strcpy(s->grade, "E");
    }
}
void displayMarksheet(const struct Student *s) 
{
    printf("\n\n");
    printf("##################################################\n");
    printf("#                OFFICIAL MARKSHEET              #\n");
    printf("##################################################\n");
    printf("  Roll Number : %-15d\n", s->rollNumber);
    printf("  Name        : %-30s\n", s->name);
    printf("--------------------------------------------------\n");
    printf("  %-25s %-15s\n", "SUBJECT", "MARKS OBTAINED");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) 
    {
        printf("  %-25s %-15d\n", subjectNames[i], s->marks[i]);
    }
    printf("--------------------------------------------------\n");
    printf("  Aggregate Total   : %d / %d\n", s->totalMarks, NUM_SUBJECTS * 100);
    printf("  Final Percentage  : %.2f%%\n", s->percentage);
    printf("  Final Grade       : %s\n", s->grade);
    printf("  Status            : %s\n", (strcmp(s->grade, "F") == 0) ? "FAILED" : "PASSED");
    printf("##################################################\n");
}
