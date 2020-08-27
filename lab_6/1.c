#include <stdlib.h>
#include <stdio.h>

int* ramp(size_t n) {
    int* consecutive = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        consecutive[i] = i + 1;
    }
    return consecutive;
}

int main(int argc, char const *argv[])
{
    int *data = ramp(5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", data[i]);
    }
    free(data);
    return 0;
}
