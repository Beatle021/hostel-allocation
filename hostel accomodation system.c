#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

struct student {
    char name[MAX_NAME_LENGTH];
    int room_number;
};

struct student students[MAX_STUDENTS];

int num_students = 0;

void add_student() {
    if (num_students == MAX_STUDENTS) {
        printf("Cannot add any more students.\n");
        return;
    }

    struct student new_student;

    printf("Enter student name: ");
    scanf("%s", new_student.name);

    printf("Enter room number: ");
    scanf("%d", &new_student.room_number);

    students[num_students++] = new_student;

    printf("Student added successfully.\n");
}

void remove_student() {
    if (num_students == 0) {
        printf("No students to remove.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];

    printf("Enter name of student to remove: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            int j;
            for (j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }

            num_students--;

            printf("Student removed successfully.\n");

            return;
        }
    }

    printf("Student not found.\n");
}

void display_students() {
    if (num_students == 0) {
        printf("No students to display.\n");
        return;
    }

    int i;
    for (i = 0; i < num_students; i++) {
        printf("%s - Room %d\n", students[i].name, students[i].room_number);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nHostel Accommodation System\n");
        printf("1. Add student\n");
        printf("2. Remove student\n");
        printf("3. Display students\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;

            case 2:
                remove_student();
                break;

            case 3:
                display_students();
                break;

            case 4:
                printf("Goodbye.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

