#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "students.dat"
typedef struct {
    int roll_no;
    char name[50];
    char course[50];
    float gpa;
} Student;
void add_student();
void display_all();
void search_student();
void update_student();
void delete_student();
void flush_input();
int main() 
{
    int choice;
    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student Record by Roll No\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            flush_input();
            continue;
        }
        switch (choice) {
            case 1: add_student(); break;
            case 2: display_all(); break;
            case 3: search_student(); break;
            case 4: update_student(); break;
            case 5: delete_student(); break;
            case 6: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void add_student() {
    FILE *fp = fopen(FILE_NAME, "ab"); 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);
    flush_input();
    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; 
    printf("Enter Course Name: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = '\0';
    printf("Enter GPA: ");
    scanf("%f", &s.gpa);
    fwrite(&s, sizeof(Student), 1, fp); 
    fclose(fp);
    printf("Record added successfully!\n");
}
void display_all() {
    FILE *fp = fopen(FILE_NAME, "rb"); 
    if (fp == NULL) {
        printf("\nNo records found. Please add a student first.\n");
        return;
    }
    Student s;
    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-20s %-15s %-5s\n", "Roll No", "Name", "Course", "GPA");
    printf("-------------------------------------------------------------\n");
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        printf("%-10d %-20s %-15s %-5.2f\n", s.roll_no, s.name, s.course, s.gpa);
    }
    printf("-------------------------------------------------------------\n");
    fclose(fp);
}
void search_student() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }
    int target_roll;
    int found = 0;
    Student s;
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &target_roll);
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == target_roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", s.roll_no);
            printf("Name:        %s\n", s.name);
            printf("Course:      %s\n", s.course);
            printf("GPA:         %.2f\n", s.gpa);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student record with Roll Number %d not found.\n", target_roll);
    }
    fclose(fp);
}
void update_student() {
    FILE *fp = fopen(FILE_NAME, "rb+"); 
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }
    int target_roll;
    int found = 0;
    Student s;
    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &target_roll);
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == target_roll) {
            found = 1;
            flush_input();
            printf("Enter New Name: ");
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = '\0';
            printf("Enter New Course: ");
            fgets(s.course, sizeof(s.course), stdin);
            s.course[strcspn(s.course, "\n")] = '\0';
            printf("Enter New GPA: ");
            scanf("%f", &s.gpa);
            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            printf("Record updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student record with Roll Number %d not found.\n", target_roll);
    }
    fclose(fp);
}
void delete_student() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }
    FILE *temp_fp = fopen("temp.dat", "wb");
    if (temp_fp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }
    int target_roll;
    int found = 0;
    Student s;
    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &target_roll);
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll_no == target_roll) {
            found = 1; 
        } else {
            fwrite(&s, sizeof(Student), 1, temp_fp);
        }
    }
    fclose(fp);
    fclose(temp_fp);
    if (found) {
        remove(FILE_NAME);            
        rename("temp.dat", FILE_NAME); 
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.dat"); 
        printf("Student record with Roll Number %d not found.\n", target_roll);
    }
}
