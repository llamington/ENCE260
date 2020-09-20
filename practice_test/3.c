#include <stdio.h>

int main()
{
    int start, step;
    scanf("%d %d", &start, &step);
    for(int i = 0; i < 6; i++) {
        printf("%d\n", start + i * step);
    }
}