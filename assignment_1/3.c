#include "stdlib.h"
#include "stdio.h"


int splitInput(unsigned char input[], size_t inputLength, int section, unsigned char part[], size_t maxPartLength)
{
    unsigned int i = 0;
    unsigned int marker = input[i++];
    unsigned int index;
    while (input[i] != marker)
    {
        i++;
    }
    if (section == 1)
    {
        index = 0;
        i++;
        while (i < inputLength)
        {
            if (i >= maxPartLength)
            {
                return -1;
            }
            part[index++] = input[i++];
        }
        return index;
    }
    else if (section == 0)
    {
        index = 1;
        unsigned int part_index = 0;
        while (index < inputLength && index < i)
        {
            if (part_index >= maxPartLength)
            {
                return -1;
            }
            part[part_index++] = input[index++];
        }
        return index - 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{

#define MAX_INPUT_MESSAGE_LENGTH 4096
#define MAX_KEY_LENGTH 1024
#define MAX_TEXT_LENGTH 3072

    unsigned char input[MAX_INPUT_MESSAGE_LENGTH] = {33, 84, 104, 101, 75, 110, 111, 99, 107, 33, 40, 80, 74, 107, 82, 94, 74};
    int inputLength = 17;

    int section;
    unsigned char part[MAX_TEXT_LENGTH];
    int partLength;

    section = 1;
    partLength = splitInput(input, inputLength, section, part, MAX_TEXT_LENGTH);
    printf("Section[%d] length (%d):", section, partLength);
    for (int i; i < partLength; i++)
        printf(" %u", part[i]);
    printf("\n");
}
