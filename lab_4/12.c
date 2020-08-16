#include "stdio.h"

int tokenCopy(char *dest, const char *src, int destSize) {
    int i = 0;
    int counts = 0;
    while (i < destSize-1 && *(i + src) != ' ' && *(i + src) != '\0') {
        *(i + dest) = *(i + src);
        i++;
        counts++;
    }
    *(i + dest) = '\0';
    return counts;
}

int main(int argc, char const *argv[])
{
    char buff[3];
    int n = tokenCopy(buff, "This is a string", 3);
    printf("%d '%s'\n", n, buff);
    return 0;
}
