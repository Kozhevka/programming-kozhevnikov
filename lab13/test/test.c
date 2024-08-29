/**
 * @file test.c
 * @brief Файл тестування для функцій обходу структури директорій.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/lib.h"

/**
 * @brief Тестова функція для print_directory_structure.
 * 
 * Ця функція тестує виведення структури директорій, створюючи приклад
 * структури директорій та записуючи її у тестовий вихідний файл.
 */
void test_print_directory_structure() {
    char *test_path = "./";
    FILE *output_fp = fopen("test_output.txt", "w");
    print_directory_structure(test_path, output_fp);
    fclose(output_fp);

    printf("Тест завершено. Перевірте файл test_output.txt для результатів.\n");
}

int main() {
    test_print_directory_structure();
    return 0;
}
