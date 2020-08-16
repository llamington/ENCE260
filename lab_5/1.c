#include "stdio.h"
#include "stdlib.h"

struct student_s {
    char* name;
    int age;
    struct student_s* next;
} student;

struct student_s anotherStudent;

void printOneStudent(struct student_s student)
{
    printf("%s (%d)\n", student.name, student.age);
}

void printStudents(const struct student_s* student) {
    while (student != NULL) {
        printOneStudent(*student);
        student = student->next;
    }
}

int main(void) {
    student.name = "Agnes McGurkinshaw";
    student.age = 97;
    student.next = &anotherStudent;

    anotherStudent.name = "Jingwu Xiao";
    anotherStudent.age = 21;
    anotherStudent.next = NULL;

    printStudents(&student);
    return EXIT_SUCCESS;
}