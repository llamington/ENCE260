#include <stdio.h>

int main(void) {
    float rushHeight = 0;
    float screeHeight = 0;
    float slideBack = 0;
    float currentHeight = 0;
    scanf("%f %f %f", &screeHeight, &rushHeight, &slideBack);
    int numRushes = 0;
    while(currentHeight < screeHeight) {
        currentHeight += rushHeight;
        numRushes++;
        if(currentHeight < screeHeight) {
            currentHeight -= slideBack;
        }
    }
    printf("%d\n", numRushes);
}