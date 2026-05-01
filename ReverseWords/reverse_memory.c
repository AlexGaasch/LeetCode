#include "reverse.h"

char* reverseWords(char* s) {
    size_t len = strlen(s);
    char *result = malloc(len + 1);
    size_t read = len;
    size_t write = 0;

    if (result == NULL)
        return NULL;

    while (read > 0)
    {
        while (read > 0 && s[read - 1] == ' ')
            read--;

        if (read == 0)
            break;

        size_t end = read - 1;

        while (read > 0 && s[read - 1] != ' ')
            read--;

        if (write > 0)
            result[write++] = ' ';

        for (size_t i = read; i <= end; i++)
            result[write++] = s[i];
    }

    result[write] = '\0';
    return result;
}