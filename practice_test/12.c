#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *description;
    float duration; // hours
    int priority;
} Task;

Task *newTask(char *description, float duration, int priority)
{
    Task* new_t = malloc(sizeof(Task));
    char* desc = malloc(strlen(description) + 1);
    strncpy(desc, description, strlen(description) + 1);
    new_t->description = desc;
    new_t->duration = duration;
    new_t->priority = priority;
    return new_t;
}

void freeTask(Task *task)
{
    free(task->description);
    free(task);
}

int main(int argc, char const *argv[])
{
    Task *task = newTask("Studying for ENCE260", 2.5f, 1);
    printf("Task \'%s\' (priority %d) takes %.1f hours.\n", task->description, task->priority, task->duration);
    freeTask(task);
    return 0;
}
