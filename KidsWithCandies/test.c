#include "kids.h"

int total_tests = 0;
int passed_tests = 0;

double total_time = 0.0;
size_t total_memory = 0;

void print_bool_array(bool* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%s", arr[i] ? "true" : "false");
        if (i < size - 1)
            printf(", ");
    }
    printf("]");
}

int arrays_equal(bool* a, bool* b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

void run_test(int test_num, int* candies, int size, int extra, bool* expected, int expectedSize) {
    clock_t start = clock();

	total_tests++;

    int returnSize = 0;
	int passed = 0;
    bool* result = kidsWithCandies(candies, size, extra, &returnSize);

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    size_t mem_used = size * sizeof(bool);

    printf("========= TEST %d =========\n", test_num);

    if (result == NULL) {
        printf("Expected:    ");
        print_bool_array(expected, expectedSize);
        printf("\nGot:         NULL\n");
        printf("Time:        %.6fs\n", time_taken);
        printf("Mem:         %zu bytes\n\n\n", mem_used);
        return;
    }

    if (returnSize != expectedSize || !arrays_equal(result, expected, expectedSize)) {
        printf("\033[31mFAIL\033[0m\n");
        printf("Candies:     [");
        for (int i = 0; i < size; i++) {
            printf("%d", candies[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]\n");
        printf("Extra:       %d\n", extra);

        printf("Expected:    ");
        print_bool_array(expected, expectedSize);
        printf("\nGot:         ");
        print_bool_array(result, returnSize);
        printf("\n");
    } else {
        printf("\033[32mPASS\033[0m\n");
		passed = 1;
    }

    printf("Time:        %.6f s\n", time_taken);
    printf("Mem:         %zu bytes\n\n\n", mem_used);

	if (passed)
		passed_tests++;
	total_time += time_taken;
	total_memory += mem_used;

    free(result);
}

int main() {
    bool exp1[] = {true, true, true, false, true};
    int c1[] = {2, 3, 5, 1, 3};

    bool exp2[] = {true, false, false, false, false};
    int c2[] = {4, 2, 1, 1, 2};

    bool exp3[] = {true, false, true};
    int c3[] = {12, 1, 12};

    bool exp4[] = {true};
    int c4[] = {5};

    bool exp5[] = {true, true, true};
    int c5[] = {1, 1, 1};

    bool exp6[] = {true, true, true, true};
    int c6[] = {1, 2, 3, 4};

    run_test(1, c1, 5, 3, exp1, 5);
    run_test(2, c2, 5, 1, exp2, 5);
    run_test(3, c3, 3, 3, exp3, 3);
    run_test(4, c4, 1, 0, exp4, 1);
    run_test(5, c5, 3, 0, exp5, 3);
    run_test(6, c6, 4, 10, exp6, 4);

	printf("========= SUMMARY =========\n");

	double percent = (total_tests == 0) ? 0.0 :
					((double)passed_tests / total_tests) * 100.0;

	printf("Passed:      %d/%d (%.2f%%)\n", passed_tests, total_tests, percent);
	printf("Total Time:  %.6f s\n", total_time);
	printf("Total Mem:   %zu bytes\n", total_memory);

    return 0;
}