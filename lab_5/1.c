#include "stdio.h"
#include "stdlib.h"

struct student_s {
    char* name;
    int age;
    struct student_s* next;
    double height;
};


void printOneStudent(struct student_s student)
{
    printf("%s (%d), height %.2f m\n", student.name, student.age, student.height);
}

void printStudents(const struct student_s* student) {
    while (student != NULL) {
        printOneStudent(*student);
        student = student->next;
    }
}

int main(void) {

    struct student_s student;
    struct student_s anotherStudent;

    student.name = "Agnes McGurkinshaw";
    student.age = 97;
    student.next = &anotherStudent;
    student.height = 1.64;

    anotherStudent.name = "Jingwu Xiao";
    anotherStudent.age = 21;
    anotherStudent.next = NULL;
    anotherStudent.height = 1.83;

    printStudents(&student);
    return EXIT_SUCCESS;
}