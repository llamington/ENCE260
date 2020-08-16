#include "stdio.h"
#include "stdlib.h"

char *mystrrchr(char *s, int c)
{
    int i = 0;
    char* index = NULL;
    while(*(s+i) != '\0') {
        if (*(s + i) == c) {
            index = (s + i);
        }
        i++;
    }
    return index;
}

int main(int argc, char const *argv[])
{
    char *s = "ENCE260";
    char *foundAt = mystrrchr(s, 'E');
    if (foundAt == NULL)
    {
        puts("Not found");
    }
    else
    {
        printf("%zu\n", foundAt - s);
    }
    return 0;
}
