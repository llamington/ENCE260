#include <string.h>
#include <stdio.h>


int *pairSumSearch(int *data, int numEls, int pairSum) {
    int i = 1;
    int last_element = data[i];
    while (i < numEls) {
        if(data[i] + last_element == pairSum) {
            return &data[i - 1];
        }
        last_element = data[i];
        i++;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = pairSumSearch(data, 10, 19);
    if (p != NULL)
    {
        printf("Found at position %zd\n", p - data);
    }
    else
    {
        puts("Not found");
    }
}
