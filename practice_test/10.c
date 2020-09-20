#include <stdio.h>

typedef struct {
    char *streetname;
    int number;
    char unit;
} Address;

int main(void)
{
    Address home = {"Baker Street", 221, 'B'};
    printf("The name's Sherlock Holmes, and the address is %d-%c %s.\n", home.number, home.unit, home.streetname);
}