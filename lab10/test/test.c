#include <stdio.h>
#include <assert.h>
#include "../src/lib.h"

void test_extract_diagonal_and_sort() 
{
    printf("Testing extract_diagonal_and_sort...\n");
    int matrix[3][3] = {{1, 2, 3}, {4, 9, 6}, {7, 8, 5}};

    printf("Original matrix:\n");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int diagonal[3];
    extract_diagonal((int *)matrix, 3, diagonal);

    printf("Original diagonal:\n");
    for (int i = 0; i < 3; i++) 
    {
        printf("%d ", diagonal[i]);
    }
    printf("\n");

    sort_array(diagonal, 3);

    printf("Sorted diagonal:\n");
    for (int i = 0; i < 3; i++) 
    {
        printf("%d ", diagonal[i]);
    }
    printf("\n");

    // Sort check
    for (int i = 0; i < 2; i++) 
    {
        assert(diagonal[i] <= diagonal[i + 1]);
    }

    printf("Test for extract_diagonal_and_sort passed.\n");
}

int main() 
{
    printf("Running tests...\n");
    test_extract_diagonal_and_sort();
    printf("All tests passed successfully.\n");
    return 0;
}