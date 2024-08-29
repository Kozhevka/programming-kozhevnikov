/**
 * @file main.c
 * @brief Головний файл програми для роботи з односпрямованим списком структур Car.
 */

#include "list.h"
#include "menu.h"
#include <stdio.h>

/**
 * @brief Головна функція програми.
 * @param argc Кількість аргументів командного рядка.
 * @param argv Аргументи командного рядка.
 * @return Статус виконання програми.
 */
int main(int argc, char *argv[]) {
    CarList list;
    initList(&list);

    if (argc > 1) {
        readFromFile(&list, argv[1]);
    }

    handleUserInput(&list);

    freeList(&list);
    return 0;
}
