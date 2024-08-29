
/**
 * @file lib.c
 * @brief Реалізація функцій для обходу структури директорій.
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "lib.h"

/**
 * @brief Вивести структуру директорій, починаючи з вказаного шляху.
 * 
 * Ця функція ініціює обхід дерева директорій.
 * 
 * @param path Початковий шлях до дерева директорій.
 * @param output_fp Вказівник на файл для запису, де буде записана структура.
 */
void print_directory_structure(const char *path, FILE *output_fp) 
{
    traverse_directory(path, output_fp, 0);
}

/**
 * @brief Рекурсивний обхід директорії та виведення її структури.
 * 
 * Ця функція рекурсивно обходить дерево директорій, виводячи кожну директорію
 * та файл з відступами для представлення структури.
 * 
 * @param path Поточний шлях у дереві директорій.
 * @param output_fp Вказівник на файл для запису, де буде записана структура.
 * @param level Поточний рівень відступів (глибина у дереві директорій).
 */

void traverse_directory(const char *path, FILE *output_fp, int level) 
{
    DIR *dir;
    struct dirent *entry;
    struct stat entry_stat;
    char new_path[1024];

    if (!(dir = opendir(path))) return;

    while ((entry = readdir(dir)) != NULL) 
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);
        stat(new_path, &entry_stat);

        for (int i = 0; i < level; i++) 
        {
            fprintf(output_fp, "    ");
        }

        if (S_ISDIR(entry_stat.st_mode)) 
        {
            fprintf(output_fp, "%s/\n", entry->d_name);
            traverse_directory(new_path, output_fp, level + 1);
        } 
        else 
        {
            fprintf(output_fp, "%s\n", entry->d_name);
        }
    }
    closedir(dir);
}
