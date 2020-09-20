#include <stdlib.h>

typedef struct
{
    int x;
    int y;
    int z;
} Vector3d;

Vector3d vector(int x, int y, int z)
{
    Vector3d* new_v = malloc(sizeof(Vector3d));
    new_v->x = x;
    new_v->y = y;
    new_v->z = z;
    return *new_v;
}

Vector3d vectorAdd(Vector3d a, Vector3d b)
{
    Vector3d *new_v = malloc(sizeof(Vector3d));
    new_v->x = a.x + b.x;
    new_v->y = b.y + a.y;
    new_v->z = a.z + b.z;
    return *new_v;
}

int main(int argc, char const *argv[])
{
    Vector3d v1 = vector(1, 4, -1);
    Vector3d v2 = vector(2, 4, -1);
    Vector3d v3 = vectorAdd(v1, v2);
    printf("(%d, %d, %d)\n", v3.x, v3.y, v3.z);
    return 0;
}
