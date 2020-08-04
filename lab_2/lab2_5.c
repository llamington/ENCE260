#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num = 0;
    do {
        scanf("%d", &num);
        printf("%d\n", num);
    } while(num != 42);
}