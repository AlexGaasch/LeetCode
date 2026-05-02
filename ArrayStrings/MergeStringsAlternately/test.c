#include "merge.h"

int total_tests = 0;
int passed_tests = 0;

double total_time = 0.0;
size_t total_memory = 0;

void run_test(int test_num, char* w1, char* w2, char* expected) {
    clock_t start = clock();

    char* result = mergeAlternately(w1, w2);

    clock_t end = clock();
	total_tests++;
	int passed = 0;
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    size_t mem_used = strlen(w1) + strlen(w2) + 1; // bytes allocated

    if (result == NULL) {
		printf("========= TEST %d =========\n", test_num);
		printf("Expected:	%s\n", expected);
		printf("Got:		NULL\n");
		printf("Time:		%.6fs\n", time_taken);
		printf("Mem:		%zu bytes\n", mem_used);
		printf("\n\n\n");
        return;
    }

	printf("========= TEST %d =========\n", test_num);
	if (strcmp(expected, result) == 0) {
		printf("\033[32mPASS\033[0m\n");
		passed = 1;
	}
	else {
		printf("\033[31mFAIL\033[0m\n");
		printf("Expected:	%s\n", expected);
		printf("Got:		%s\n", result);
	}
	printf("Time:		%.6f s\n", time_taken);
	printf("Mem:		%zu bytes\n", mem_used);
	printf("\n\n\n");

	total_time += time_taken;
	total_memory += mem_used;
	if (passed)
		passed_tests++;
    free(result);
}

int main() {
    run_test(1, "", "", "");
    run_test(2, "a", "", "a");
    run_test(3, "", "b", "b");
    run_test(4, "abc", "def", "adbecf");
    run_test(5, "ab", "wxyz", "awbxyz");
    run_test(6, "abcd", "xy", "axbycd");
    run_test(7, "a", "12345", "a12345");
    run_test(8, "hello", "X", "hXello");
    run_test(9, "AAAA", "bbbb", "AbAbAbAb");
    run_test(10, "123", "4567", "1425367");

	printf("========= SUMMARY =========\n");

	double percent = (total_tests == 0) ? 0.0 :
					((double)passed_tests / total_tests) * 100.0;

	printf("Passed:      %d/%d (%.2f%%)\n", passed_tests, total_tests, percent);
	printf("Total Time:  %.6f s\n", total_time);
	printf("Total Mem:   %zu bytes\n", total_memory);
    return 0;
}