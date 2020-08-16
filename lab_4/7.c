#include <stdio.h>
#include <stdbool.h>

bool isInData2(char data[], int arraySize, char *ptr) {
    char* min_address = data;
    char* max_address = data + arraySize - 1;
    if(ptr <= max_address && ptr >= min_address) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    char x;
    char thing[3];
    char y;
    printf("%d\n", isInData2(thing, 3, &x));
    printf("%d\n", isInData2(thing, 3, &thing[0]));
    printf("%d\n", isInData2(thing, 3, &thing[1]));
    printf("%d\n", isInData2(thing, 3, &thing[2]));
    printf("%d\n", isInData2(thing, 3, &thing[3]));
    printf("%d\n", isInData2(thing, 3, &y));
    return 0;
}
