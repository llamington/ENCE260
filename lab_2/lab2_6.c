#include <stdio.h>

int main(void) {
    int num = 0;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++) {
        printf("%d\n", i*i);
    }
}