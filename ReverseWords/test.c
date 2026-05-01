#include "reverse.h"

void run_test(int test_num, char* input, char* expected) {
    clock_t start = clock();

    char* result = reverseWords(input);

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    size_t mem_used = strlen(input) + 1; // approximate allocation

    if (result == NULL) {
        printf("========= TEST %d =========\n", test_num);
        printf("Input:       \"%s\"\n", input);
        printf("Expected:    \"%s\"\n", expected);
        printf("Got:         NULL\n");
        printf("Time:        %.6fs\n", time_taken);
        printf("Mem:         %zu bytes\n\n\n", mem_used);
        return;
    }

    printf("========= TEST %d =========\n", test_num);
    if (strcmp(expected, result) == 0) {
        printf("\033[32mPASS\033[0m\n");
    } else {
        printf("\033[31mFAIL\033[0m\n");
        printf("Input:       \"%s\"\n", input);
        printf("Expected:    \"%s\"\n", expected);
        printf("Got:         \"%s\"\n", result);
    }
    printf("Time:        %.6f s\n", time_taken);
    printf("Mem:         %zu bytes\n\n\n", mem_used);

    free(result);
}

int main() {
    run_test(1, "", "");
    run_test(2, "a", "a");
    run_test(3, "hello", "hello");
    run_test(4, "hello world", "world hello");
    run_test(5, "  hello world  ", "world hello");
    run_test(6, "the sky is blue", "blue is sky the");
    run_test(7, "a good   example", "example good a");
    run_test(8, "   multiple   spaces here   ", "here spaces multiple");
    run_test(9, "single", "single");
    run_test(10, " one", "one");

    return 0;
}