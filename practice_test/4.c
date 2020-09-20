#include <stdio.h>

#define MAX_LINES 100
int main() {
    int c;
    int after_13 = 0;
    scanf("%d", &c);
    int asum = 0;
    int counter = 0;
    while (c != 0 && counter <= MAX_LINES) {
        if (c == 13) {
            after_13 = 1;
        }
        else if (!after_13) {
            asum += c;
        } else {
            after_13 = 0;
        }
        scanf("%d", &c);
        counter++;
    }
    printf("%d\n", asum); 
}