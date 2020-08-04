#include "math.h"

double discriminant(double a, double b, double c) {
    return b*b - 4*a*c;
}

int main(int argc, char const *argv[])
{
    printf("%.2lf\n", discriminant(1.5, 1.5, 1.5));
    return 0;
}
