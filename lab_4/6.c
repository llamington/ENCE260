#include <stdio.h>
#include <stdbool.h>

char data[100];

bool isInData(char *address)
{
    char* min_address = data;
    char* max_address = data + 99;
    if(address <= max_address && address >= min_address) {
        return true; 
    } else return false;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", isInData(&data[99]));
    return 0;
}
