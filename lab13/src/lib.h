/**
 * @file lib.h
 * @brief Заголовний файл для функцій обходу структури директорій.
 */

#ifndef LIB_H
#define LIB_H

/**
 * @brief Вивести структуру директорій, починаючи з вказаного шляху.
 * 
 * @param path Початковий шлях до дерева директорій.
 * @param output_fp Вказівник на файл для запису, де буде записана структура.
 */
void print_directory_structure(const char *path, FILE *output_fp);

/**
 * @brief Рекурсивний обхід директорії та виведення її структури.
 * 
 * @param path Поточний шлях у дереві директорій.
 * @param output_fp Вказівник на файл для запису, де буде записана структура.
 * @param level Поточний рівень відступів (глибина у дереві директорій).
 */
void traverse_directory(const char *path, FILE *output_fp, int level);

#endif
