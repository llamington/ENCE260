void swap3(int *x, int *y, int *z) {
    int arg_array[] = {*x, *y, *z};
    int min = *x;
    int min_i = 0;
    int max = *x;
    int max_i = 0;
    for (int i = 0; i < 3; i++) {
        if(arg_array[i] < min) {
            min = arg_array[i];
            min_i = i;
        } else if (arg_array[i] > max) {
            max = arg_array[i];
            max_i = i;
        }
    }
    int middle = 3 - min_i - max_i;
    *x = min;
    *y = arg_array[middle];
    *z = max;
}

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 0;
    int c = 7;
    swap3(&a, &b, &c);
    printf("%d <= %d <= %d\n", a, b, c);
    return 0;
}
