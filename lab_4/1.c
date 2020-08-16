#include "stdio.h"

void printViaPtr(const int *intPtr)
{
    printf("%d\n", *intPtr);
}

void print2Ints(int number1, int number2) {
    printViaPtr(&number1);
    printViaPtr(&number2);
}

int main(int argc, char const *argv[])
{
    print2Ints(1, 2);
    return 0;
}
