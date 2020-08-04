#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
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
        float root_1 = (-1*b - sqrt(discriminant)) / (2.0*a);
        float root_2 = (-1*b + sqrt(discriminant)) / (2.0*a);
        if(root_1 <= root_2) {
            printf("Roots are %.4f and %.4f", root_1, root_2);
        } else {
            printf("Roots are %.4f and %.4f", root_2, root_1);
        }
    }
}
