#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
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

size_t readCipherBook(FILE *file, char text[], size_t maxTextSize){
    size_t text_size = readText(file, text, maxTextSize);
    int reduced_text_size = 0;
    int c;
    char text_no_spaces[maxTextSize];
    for(int i = 0; i < text_size; i++) {
        c = text[i];
        if (!isspace(c)) {
            text_no_spaces[reduced_text_size++] = c;
        }
    }
    text_no_spaces[reduced_text_size] = '\0';
    strncpy(text, text_no_spaces, maxTextSize);
    return reduced_text_size;
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
    textLength = readCipherBook(file, text, MAX_TEXTFILE_SIZE);
    fclose(file);

    printf("%s\n", text);
    printf("Size of cipherfile is %zu\n", textLength);
    return 0;
}