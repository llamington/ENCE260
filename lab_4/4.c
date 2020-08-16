#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void findTwoLargest(const int data[], int n, int* largest, int* second) {
    *largest = data[0];
    *second = data[1];
    if(*second > *largest) {
        *second = *largest;
    }
    for (int i = 1; i < n; i++)
    {
        if(data[i] > *largest) {
            *second = *largest;
            *largest = data[i];
        } else if (data[i] > *second)
        {
            *second = data[i];
        }
        
    }

}


int main()
{
    int data[] = {5, 4};
    int result1 = 0, result2 = 0;
    findTwoLargest(data, 2, &result1, &result2);
    printf("%d %d\n", result1, result2);
    printf("%d %d\n", data[0], data[1]);
    return 0;
}