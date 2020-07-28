#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int input;
    scanf("%u", &input);
    if (input  == 0) {
        puts("Zero");
    } else if (input % 2 == 0) {
        puts("Even");
    } else {
        puts("Odd");
    }

}