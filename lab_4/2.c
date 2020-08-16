#include "stdlib.h"
#include "stdio.h"

void swap(int *address1, int *address2) {
    int temp = *address2;
    *address2 = *address1;
    *address1 = temp; 
}

int main(int argc, char const *argv[])
{
    int i = 10, j = 20;
    swap(&i, &j);
    printf("%d %d\n", i, j);
    return 0;
}
