/**
 * @file main.c
 * @brief Головний файл програми для обходу структури директорій.
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
 * @brief Головна точка входу програми.
 * 
 * Ця функція зчитує шляхи вхідного та вихідного файлів з аргументів командного рядка,
 * відкриває ці файли, зчитує шлях до директорії з вхідного файлу та записує
 * структуру директорії у вихідний файл.
 * 
 * @param argc Кількість аргументів.
 * @param argv Вектор аргументів.
 * @return int Повертає 0 у випадку успіху, ненульове значення у випадку помилки.
 */

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *input_fp = fopen(input_file, "r");
    if (!input_fp) 
    {
        perror("Failed to open input file");
        return 1;
    }

    FILE *output_fp = fopen(output_file, "w");
    if (!output_fp) 
    {
        perror("Failed to open output file");
        fclose(input_fp);
        return 1;
    }

    char path[1024];
    fscanf(input_fp, "%s", path);
    fclose(input_fp);

    print_directory_structure(path, output_fp);

    fclose(output_fp);
    return 0;
}
