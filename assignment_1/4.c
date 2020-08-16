#include "stdlib.h"
#include "stdio.h"

void decryptMessage(unsigned char key[], size_t keyLength, unsigned char message[], size_t messageLength)
{
    unsigned int i = 0;
    unsigned int key_i = 0;
    while(i < messageLength) {
        if(key_i >= keyLength) {
            key_i = 0;
        }
        message[i] = message[i] - key[key_i];
        i++;
        key_i++;

    }
    message[i] = 0;
}

int main(int argc, char const *argv[])
{
#define MAX_INPUT_MESSAGE_LENGTH 4096
#define MAX_KEY_LENGTH 1024
#define MAX_TEXT_LENGTH 3072

    unsigned char key[MAX_KEY_LENGTH] = {23, 2};
    unsigned char message[MAX_TEXT_LENGTH] = {67, 20, 127};
    int keyLength = 2;
    int messageLength = 3;

    decryptMessage(key, keyLength, message, messageLength);
    printf("Decrypt Message (%d):", messageLength);
    for (int i = 0; i < messageLength + 1; i++)
        printf(" %u", message[i]);
    printf("\n");
    return 0;
}
