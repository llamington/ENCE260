#include "stdlib.h"
#include "stdio.h"

size_t mystrlen(const char s[]) {
    int i = 0;
    size_t counts = 0;
    while(s[i] != '\0') {
        counts++;
        i++;
    }
    return counts;
}

int main(int argc, char const *argv[])
{
    printf("%zd\n", mystrlen("ENCE260"));
    return 0;
}
