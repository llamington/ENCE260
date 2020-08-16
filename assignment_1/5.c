#include "stdlib.h"
#include "stdio.h"
#define maxArrayLength 4096
#define maxKeyLength 1022
#define maxMessageLength 3071
#define MESSAGE_SECTION 1
#define KEY_SECTION 0


int readUCharInt(unsigned char *input)
{
    int size;
    size = scanf("%hhu", input);
    return size;
}

int readInput(unsigned char input[], size_t inputMaxLength)
{
    unsigned int i = 0;
    int current = 0;
    while (current != -1)
    {
        if (i >= inputMaxLength)
        {
            return -1;
        }
        current = readUCharInt(&input[i]);
        i++;
    }
    return i - 1;
}

void decryptMessage(unsigned char key[], size_t keyLength, unsigned char message[], size_t messageLength)
{
    unsigned int i = 0;
    unsigned int key_i = 0;
    while (i < messageLength)
    {
        if (key_i >= keyLength)
        {
            key_i = 0;
        }
        message[i] = message[i] - key[key_i];
        i++;
        key_i++;
    }
    message[i] = 0;
}

int splitInput(unsigned char input[], size_t inputLength, int section, unsigned char part[], size_t maxPartLength)
{
    unsigned int i = 0;
    unsigned int marker = input[i++];
    unsigned int index;
    while (input[i] != marker) {
        i++;
    }
    if (section == 1) {
        index = 0;
        i++;
        while (i < inputLength) {
            if (i >= maxPartLength) {
                return -1;
            }
            part[index++] = input[i++];
        }
        return index;
    }
    else if (section == 0) {
        index = 1;
        unsigned int part_index = 0;
        while (index < inputLength && index < i) {
            if (part_index >= maxPartLength) {
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
    unsigned char input[maxArrayLength];
    unsigned char message[maxMessageLength];
    unsigned char key[maxKeyLength];
    int inputLength;
    int messageLength;
    int keyLength;

    inputLength = readInput(input, maxArrayLength);
    messageLength = splitInput(input, inputLength, MESSAGE_SECTION, message, maxMessageLength);
    keyLength = splitInput(input, inputLength, KEY_SECTION, key, maxKeyLength);
    decryptMessage(key, keyLength, message, messageLength);
    for (int i = 0; i < messageLength; i++)
        printf("%c", message[i]);
    printf("\n");
    return 0;
}
