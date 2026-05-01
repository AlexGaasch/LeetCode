#include "merge.h"
// My solution to get a bit better memory usage. 100% runtime (0ms) and 75% memory 8.6 MB

char* mergeAlternately(const char* word1, const char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    char* result = (char*)malloc(len1 + len2 + 1);
    if (!result) return NULL;

    int i = 0, j = 0, k = 0;

    while (i < len1 && j < len2) {
        result[k++] = word1[i++];
        result[k++] = word2[j++];
    }

    while (i < len1) {
        result[k++] = word1[i++];
    }

    while (j < len2) {
        result[k++] = word2[j++];
    }

    result[k] = '\0';
    return result;
}