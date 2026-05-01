#include "reverse.h"

char* reverseWords(char* s) {
    int len = strlen(s);
    char *result = malloc(len + 1);
    int i = len - 1, k = 0;

    while (i >= 0) {
        while (i >= 0 && s[i] == ' ')
            i--;

        if (i < 0)
            break;

        int end = i;

        while (i >= 0 && s[i] != ' ')
            i--;

        int start = i + 1;

        for (int j = start; j <= end; j++)
            result[k++] = s[j];

        result[k++] = ' ';
    }

    if (k > 0)
        k--;
    result[k] = '\0';
    return result;
}