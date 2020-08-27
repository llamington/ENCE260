#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXTFILE_SIZE 4096
#define MAX_FILENAME_LENGTH 80

size_t readText(FILE *file, char text[], size_t maxTextSize)
{
    int i = 0;
    int c;
    while (i < maxTextSize - 1 && (c = fgetc(file)) != EOF)
    {
        text[i++] = c;
    }
    text[i] = '\0';
    return i;
}

size_t readMessage(FILE *file, char text[], size_t maxTextSize) {
    size_t text_size = readText(file, text, maxTextSize);
    char transformed_text[maxTextSize];
    int transformed_text_index = 0;
    int c;
    for (int i = 0; i < text_size; i++) {
        c = text[i];
        if (c >= ' ' && c <= '~') {
            transformed_text[transformed_text_index++] = c - 31;
        } else if (c == '\t') {
            transformed_text[transformed_text_index++] = 96;
        } else if (c == '\n') {
            transformed_text[transformed_text_index++] = 97;
        }
    }
    transformed_text[transformed_text_index] = '\0';
    strncpy(text, transformed_text, maxTextSize);
    return transformed_text_index;
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
        printf("File not found... program will fail with segmentation fault\n");
    }
    textLength = readMessage(file, text, MAX_TEXTFILE_SIZE);
    fclose(file);

    for (size_t i = 0; i < textLength; i++)
    {
        printf("%d ", text[i]);
    }
    printf("\nSize of message is %zu\n", textLength);
    return 0;
}
