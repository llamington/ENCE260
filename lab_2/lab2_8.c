#include <stdio.h>

int main(void) {
    int n1 = 0;
    int n2 = 0;
    int is_prime = 0;
    scanf("%d %d", &n1, &n2);
    for(int i = n1; i <= n2; i++) {
        is_prime = 1;
        for(int j = 2; j < i; j++) {
            if (i % j == 0) {  
                is_prime = 0;
            }
        }
        if(is_prime) {
            printf("%d\n", i);
        }
    }
}