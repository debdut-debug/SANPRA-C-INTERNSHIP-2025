#include <stdio.h>

// Define structure for student
struct Student {
    char name[50];
    int id;
    float grade;
};

// Array to store students
struct Student students[100];
int count = 0;

// Function to add a new student
void addStudent() {
    printf("\n--- Add New Student ---\n");

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Grade: ");
    scanf("%f", &students[count].grade);

    count++;
    printf("Student added successfully!\n");
}

// Function to display all students
void viewStudents() {
    printf("\n--- All Student Records ---\n");

    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name  : %s\n", students[i].name);
        printf("ID    : %d\n", students[i].id);
        printf("Grade : %.2f\n", students[i].grade);
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n===== Student Record Manager =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
