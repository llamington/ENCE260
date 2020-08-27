#include <stdlib.h>
#include <stdio.h>

#define MAX_TEXTFILE_SIZE 4096
#define MAX_FILENAME_LENGTH 80

size_t readText(FILE *file, char text[], size_t maxTextSize) {
    int i = 0;
    int c;
    while(i < maxTextSize-1 && (c = fgetc(file)) != EOF) {
        text[i++] = c;
    }
    text[i] = '\0';
    return i;
}

int main(void)
{
    char filename[MAX_FILENAME_LENGTH] = "";
    char text[MAX_TEXTFILE_SIZE] = "";
    FILE *file = NULL;
    size_t textLength = 0;

    scanf("%80s", filename);
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File not found... program will crash with a segmentation fault\n");
    }
    textLength = readText(file, text, MAX_TEXTFILE_SIZE);
    fclose(file);

    printf("%s\n", text);
    printf("Size of textfile is %zu\n", textLength);
    return 0;
}
