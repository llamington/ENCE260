#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (b * b < 4 * a * c) {
        printf("Roots are complex\n");
    } else {
        printf("Roots are real\n");
    }
}