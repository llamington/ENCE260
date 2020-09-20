int add_sub(const int data[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += data[i];
        } else {
            sum -= data[i];
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int data[4] = {1, 2, 3, 4};
    printf("%d\n", add_sub(data, 4));
    return 0;
}
