#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num = 0;
    while(num != 42) {
        scanf("%d", &num);
        printf("%d\n", num);
    }
}