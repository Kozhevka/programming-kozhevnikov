#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "../src/lib.h"

void test_str_to_int() 
{
    const char *test_cases[] = {"123", "-456", "0", "2147483647", "-2147483648"};
    const int expected_results[] = {123, -456, 0, 2147483647, -2147483648};
    const int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; ++i) 
    {
        int result = str_to_int(test_cases[i]);
        assert(result == expected_results[i]);
    }
}

void test_str_to_float() 
{
    const char *test_cases[] = {"3.14", "-2.718", "0.0", "123.456"};
    const float expected_results[] = {3.14f, -2.718f, 0.0f, 123.456f};
    const int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; ++i) 
    {
        float result = str_to_float(test_cases[i]);
        assert(result == expected_results[i]);
    }
}

int test_main() {
    printf("Running tests...\n");

    test_str_to_int();
    test_str_to_float();

    printf("All tests passed!\n");

    return 0;
}