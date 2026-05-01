    #include "GCD.h"
	
	char* gcdOfStrings(char* str1, char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t total = len1 + len2;
    
    char* s1s2 = malloc(total + 1);
    char* s2s1 = malloc(total + 1);
    
    if (!s1s2 || !s2s1) {
        free(s1s2);
        free(s2s1);
        return calloc(1, 1);
    }
    
    strcpy(s1s2, str1);
    strcat(s1s2, str2);
    
    strcpy(s2s1, str2);
    strcat(s2s1, str1);
    
    if (strcmp(s1s2, s2s1) != 0) {
        free(s1s2);
        free(s2s1);
        return calloc(1, 1);
    }

    free(s1s2);
    free(s2s1);

    size_t a = len1, b = len2;
    while (b > 0) {
        size_t temp = b;
        b = a % b;
        a = temp;
    }
    
    char* result = malloc(a + 1);
    if (!result)
        return calloc(1, 1);
    
    strncpy(result, str1, a);
    result[a] = '\0';
    
    return result;
}