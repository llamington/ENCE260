int myIndex(int data[], int *element) {
    return element - data;
}

int main(int argc, char const *argv[])
{
    int data[30];
    int *p = &data[17];
    printf("Index is %d\n", myIndex(data, p));
    return 0;
}
