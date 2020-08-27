#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stringpair_s
{
    char *first;
    char *second;
} StringPair;

StringPair *newStringPair(const char *s1, const char *s2) {
    StringPair *new = malloc(sizeof(StringPair));
    new->first = malloc(strlen(s1)+1);
    new->second = malloc(strlen(s2)+1);
    strncpy(new->first, s1, strlen(s1));
    strncpy(new->second, s2, strlen(s2));
    new->first[strlen(s1)] = '\0';
    new->second[strlen(s2)] = '\0';
    return new;
}

    int main(void)
{
    char s1[] = {'a', 'b', 'c', 0, 'x', 'y', 'z'};
    char s2[] = {'1', '2', '3', 0, '*', '*', '*'};
    StringPair *sp = NULL;

    sp = newStringPair(s1, s2);

    // Before printing, alter the initial strings to ensure
    // the function hasn't just copied the pointers.
    strncpy(s1, "BAM", sizeof(s1));
    strncpy(s2, "POW", sizeof(s2));

    // Now print the new StringPair.
    printf("String pair: ('%s', '%s')\n",
           sp->first, sp->second);

    // Lastly free all dynamic memory involved.
    free(sp->first);
    free(sp->second);
    free(sp);
}