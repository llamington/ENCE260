#include <stdio.h>

typedef struct queue_t
{
    char* username;
    struct queue_t *next;

} QueueElement;



void printQueue(QueueElement *queue, const char *message)
{
    QueueElement *current = queue;
    printf("Queue %s:", message);

    while (current != NULL)
    {
        printf(" %s", current->username);
        current = current->next;
    }
    printf("\n");
}

QueueElement *appendToQueue(QueueElement *start, QueueElement *addTo) {
    QueueElement* current = start;
    if (current == NULL) {
        start = addTo;
        return addTo;
    }
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = addTo;
    return start;
}

    // Simple test of the student queue
int main(void)
{
    QueueElement *queue = NULL;
    QueueElement stud1 = {"abc24", NULL};
    QueueElement stud2 = {"pqr33", NULL};

    printQueue(queue, "at start");
    queue = appendToQueue(queue, &stud1);
    printQueue(queue, "after appending abc24");
    queue = appendToQueue(queue, &stud2);
    printQueue(queue, "after appending pqr33");
}