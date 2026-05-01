void run_test(int test_num, const char* w1, const char* w2, const char* expected) {
    char* result = mergeAlternately(w1, w2);

    if (result == NULL) {
        printf("test%d : expected: %s, got: NULL\n", test_num, expected);
        return;
    }

    printf("test%d : expected: %s, got: %s\n", test_num, expected, result);
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
    run_test(8, "hello", "X", "hXe llo");
    run_test(9, "AAAA", "bbbb", "AbAbAbAb");
    run_test(10, "123", "4567", "1425367");

    return 0;
}