#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char *name;
    int age;
    double height;
} Person;

Person *newPerson(char *name, int age, double height) {
    Person* new = malloc(sizeof(Person));
    new->name = malloc(strlen(name) + 1);
    strncpy(new->name, name, strlen(name) + 1);
    new->age = age;
    new->height = height;
    return new;
}

void freePerson(Person *person) {
    free(person->name);
    free(person);
}

int main(int argc, char const *argv[])
{
    Person *employee = newPerson("Billy", 30, 1.68);
    printf("%s is age %d and is %.2f m tall\n", employee->name, employee->age, employee->height);
    freePerson(employee);
    return 0;
}
