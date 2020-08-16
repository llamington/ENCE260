#include "stdio.h"

int countMatches(int n, int data[], int searchValue) {
    int counts = 0;
    for(int i = 0; i <= n; i++) {
        if (data[i] == searchValue) {
            counts++;
        }
    }
    return counts;
}

int main(int argc, char const *argv[])
{
    int nums[] = {10, 20, 30};
    printf("%d\n", countMatches(3, nums, 1));
    return 0;
}
