#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    float a;
    float b;
    float c;

    scanf("%f %f %f", &a, &b, &c);
    float discriminant = pow(b, 2) - 4*a*c;
    if (a == 0) {
        puts("Not a quadratic");
    } else if (discriminant < 0) {
        puts("Complex roots");
    } else {
        float negative_root = (-1*b - sqrt(discriminant)) / (2.0*a);
        printf("%f", negative_root);
    }
}
