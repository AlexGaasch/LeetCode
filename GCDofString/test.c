#include "GCD.h"

void run_test(int test_num, char* s1, char* s2, char* expected) {
    clock_t start = clock();

    char* result = gcdOfStrings(s1, s2);

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    size_t mem_used = strlen(s1) + strlen(s2) + 1;

    printf("========= TEST %d =========\n", test_num);

    if (result == NULL) {
        printf("Expected:    \"%s\"\n", expected);
        printf("Got:         NULL\n");
        printf("Time:        %.6fs\n", time_taken);
        printf("Mem:         %zu bytes\n\n\n", mem_used);
        return;
    }

    if (strcmp(expected, result) == 0) {
        printf("\033[32mPASS\033[0m\n");
    } else {
        printf("\033[31mFAIL\033[0m\n");
        printf("Input1:      \"%s\"\n", s1);
        printf("Input2:      \"%s\"\n", s2);
        printf("Expected:    \"%s\"\n", expected);
        printf("Got:         \"%s\"\n", result);
    }

    printf("Time:        %.6f s\n", time_taken);
    printf("Mem:         %zu bytes\n\n\n", mem_used);

    free(result);
}

int main() {
    run_test(1, "ABCABC", "ABC", "ABC");
    run_test(2, "ABABAB", "ABAB", "AB");
    run_test(3, "LEET", "CODE", "");
    run_test(4, "AAAAAA", "AAA", "AAA");
    run_test(5, "A", "A", "A");
    run_test(6, "ABCDEF", "ABC", "");
    run_test(7, "XYZXYZXYZ", "XYZXYZ", "XYZ");
    run_test(8, "ABABABAB", "ABAB", "ABAB");
    run_test(9, "AAAA", "AA", "AA");
    run_test(10, "ABCD", "ABCDABCD", "ABCD");

    return 0;
}