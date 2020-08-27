#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *skipping(const char *s) {
    int len = strlen(s);
    char* second_str;
    if (len % 2 == 0) {
        second_str = malloc(len / 2 + 1);
    } else {
        second_str = malloc(len / 2 + 2);
    }
    int s_i = 0;
    int i = 0;
    for (i; i < len; i++) {
        if (i % 2 == 0) {
            second_str[s_i++] = s[i];
        }
    }
    second_str[s_i] = '\0';
    return second_str;
}

int main(int argc, char const *argv[])
{

    char *s = skipping("A0B1C2D");
    printf("%s\n", s);
    free(s);
}
