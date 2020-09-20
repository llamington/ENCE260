#include <stdio.h>
#include <string.h>

char *rotateLeft(char *s) {
    size_t s_len = strlen(s);
    char new[s_len + 1];
    int counter = 1;
    while (counter < s_len) {
        new[counter - 1] = s[counter];
        counter++;
    }
    new[counter - 1] = s[0];
    new[counter] = '\0';
    strncpy(s, new, s_len + 1);
    return s;
    
}

int main(int argc, char const *argv[])
{
    char s[] = "Hello World!";
    printf("%s\n", rotateLeft(s));
    return 0;
}
