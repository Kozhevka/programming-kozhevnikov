#include <stdio.h>
#include <assert.h>
#include "lib.h"


void test_extract_diagonal() 
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int diagonal[3];
    extract_diagonal((int *)matrix, 3, diagonal);
    assert(diagonal[0] == 1 && diagonal[1] == 5 && diagonal[2] == 9);
    printf("Test for extract_diagonal passed.\n");
}


void test_sort_array() {
    int array[5] = {5, 3, 2, 4, 1};
    sort_array(array, 5);
    for (int i = 0; i < 4; i++) 
    {
        assert(array[i] <= array[i + 1]);
    }
    printf("Test for sort_array passed.\n");
}

int main() 
{
    printf("Лабораторна робота №10. Вступ до показчиків\n");


    printf("Введіть елементи квадратної матриці:\n");
    int matrix[3][3];
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }


    int diagonal[3];
    extract_diagonal((int *)matrix, 3, diagonal);
    sort_array(diagonal, 3);


    printf("Відсортована головна діагональ матриці:\n");
    for (int i = 0; i < 3; i++) 
    {
        printf("%d ", diagonal[i]);
    }
    printf("\n");

    return 0;
}