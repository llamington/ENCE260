

char** split(const char* s) {
    int c = s[0];
    int i = 0;
    while(c != ' ') {
        c = s[i++];
    }
}

int main(int argc, char const *argv[])
{
    char **words = split("He said 'hello' to me!");
    int i = 0;
    while (words[i] != NULL)
    {
        puts(words[i]);
        free(words[i]);
        i += 1;
    }
    free(words);
    return 0;
}
