#include "stdlib.h"
#include "stdio.h"
#define MAX_INPUT_MESSAGE_LENGTH 8

int readUCharInt(unsigned char *input)
{
    int size;
    size = scanf("%hhu", input);
    return size;
}

int readInput(unsigned char input[], size_t inputMaxLength) {
    unsigned int i = 0;
    int current = 0;
    while (current != -1)
    {
        if(i >= inputMaxLength) {
            return -1;
        }
        current = readUCharInt(&input[i]);
        i++;
    }
    return i-1;

}

int main(int argc, char const *argv[])
{

    unsigned char input[MAX_INPUT_MESSAGE_LENGTH];
    int inputLength;

    inputLength = readInput(input, MAX_INPUT_MESSAGE_LENGTH);
    printf("Message (%d):", inputLength);
    for (int i = 0; i < inputLength; i++)
        printf(" %u", input[i]);
    printf("\n");
    return 0;
}
