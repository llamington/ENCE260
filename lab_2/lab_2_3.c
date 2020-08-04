#include <stdio.h>

int gringe(int boink, int flunk) 
{
    return boink == flunk ? 42 : flunk - 11;
}

int main(void) {
    printf("%d\n", gringe(53, 54));
}