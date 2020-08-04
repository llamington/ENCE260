#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

int main(void) {
    int counts[26] = {0};
    int c = 0;
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c) != 0) {
            counts[toupper(c) - 65]++;
        }
    }
    for(int i = 0; i <= 25; i++) {
        printf("%c: %d\n", i + 65, counts[i]);
    }
    
    
}