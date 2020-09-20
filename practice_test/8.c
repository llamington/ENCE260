int mystrnlen(const char *s, int maxlen) {
    int i = 0;
    while(s[i] != '\0' && i < maxlen) {
        i++;
    }
    if (s[i] == '\0') {
        return i;
    } else {
        return maxlen;
    }
    
}

int main(int argc, char const *argv[])
{
    printf("%d\n", mystrnlen("ENCE260", 6));
    return 0;
}

