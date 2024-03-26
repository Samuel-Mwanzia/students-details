/*MWANZIA SAMUEL
ENE212-0225/2019*/
#include <stdio.h>
#include <string.h>

#define MAX_COURSES 10
#define MAX_STUDENTS 10

typedef struct {
    char first_name[20];
    char last_name[20];
    char reg_number[20];
    char courses[MAX_COURSES][50];
    int num_courses;
} Student;

void display_student(Student *student) {
    printf("Student Details:\n");
    printf("Name: %s %s\n", student->first_name, student->last_name);
    printf("Registration Number: %s\n", student->reg_number);
    printf("Courses: \n");
    for (int i = 0; i < student->num_courses; i++) {
        printf("%d. %s\n", i+1, student->courses[i]);
    }
}

void edit_student(Student *student) {
    int choice;
    printf("What would you like to edit?\n");
    printf("1. Name\n2. Registration Number\n3. Courses\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter new first name: ");
            scanf("%s", student->first_name);
            printf("Enter new last name: ");
            scanf("%s", student->last_name);
            break;
        case 2:
            printf("Enter new registration number: ");
            scanf("%s", student->reg_number);
            break;
        case 3:
            printf("Enter new courses (enter '0' to stop):\n");
            student->num_courses = 0;
            char temp[50];
            while(1) {
                scanf("%s", temp);
                if(strcmp(temp, "0") == 0) break;
                strcpy(student->courses[student->num_courses], temp);
                student->num_courses++;
            }
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int num_students = 0;
    while(1) {
        printf("Enter the details for student %d (or enter '0' to stop):\n", num_students + 1);
        Student new_student;
        printf("First Name: ");
        scanf("%s", new_student.first_name);
        if(strcmp(new_student.first_name, "0") == 0) break;
        printf("Last Name: ");
        scanf("%s", new_student.last_name);
        printf("Registration Number: ");
        scanf("%s", new_student.reg_number);
        printf("Enter courses (enter '0' to stop):\n");
        new_student.num_courses = 0;
        char temp[50];
        while(1) {
            scanf("%s", temp);
            if(strcmp(temp, "0") == 0) break;
            strcpy(new_student.courses[new_student.num_courses], temp);
            new_student.num_courses++;
        }
        if(num_students < MAX_STUDENTS) {
            students[num_students] = new_student;
            num_students++;
        } else {
            printf("Maximum number of students reached, cannot add more students.\n");
        }
    }
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i+1);
        display_student(&students[i]);
    }
    while(1) {
        printf("Do you want to edit any student details? (1/0): ");
        int choice;
        scanf("%d", &choice);
        if(choice == 1) {
            int student_num;
            printf("Enter the number of the student to edit: ");
            scanf("%d", &student_num);
            if(student_num > 0 && student_num <= num_students) {
                edit_student(&students[student_num-1]);
            } else {
                printf("Invalid student number.\n");
            }
        } else {
            break;
        }
    }
    return 0;
}
