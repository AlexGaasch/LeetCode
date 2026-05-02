#include "merge.h"
// Easy solution to get 100% runtime (0ms, 8.8 Memory)

int ft_strlen(char *str)
{
    int i = 0;

    while(str[i])
        i++;
    return i;
}

char *mergeAlternately(char *word1, char *word2)
{
    char *merged;
    int i = 0;
    int j = 0;

    merged = malloc(ft_strlen(word1) + ft_strlen(word2) + 1);
    if (!merged)
        return NULL;

    while (word1[i] && word2[j])
    {
        merged[i + j] = word1[i];
        i++;
        merged[i + j] = word2[j];
        j++;
    }

    while (word1[i])
    {
        merged[i + j] = word1[i];
        i++;
    }

    while (word2[j])
    {
        merged[i + j] = word2[j];
        j++;
    }

    merged[i + j] = '\0';
    return merged;
}