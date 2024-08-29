/**
 * @file list.c
 * @brief Реалізація функцій для роботи з динамічним масивом CarList.
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Ініціалізує динамічний масив CarList.
 * @param list Вказівник на CarList.
 */
void initList(CarList *list) {
    list->size = 0;
    list->capacity = 2;
    list->data = (Car *)malloc(list->capacity * sizeof(Car));
}

/**
 * @brief Звільняє пам'ять, зайняту масивом CarList.
 * @param list Вказівник на CarList.
 */
void freeList(CarList *list) {
    free(list->data);
    list->size = 0;
    list->capacity = 0;
}

/**
 * @brief Додає новий автомобіль до масиву CarList.
 * @param list Вказівник на CarList.
 * @param car Автомобіль для додавання.
 */
void addCar(CarList *list, Car car) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (Car *)realloc(list->data, list->capacity * sizeof(Car));
    }
    list->data[list->size++] = car;
}

/**
 * @brief Видаляє автомобіль з масиву CarList за індексом.
 * @param list Вказівник на CarList.
 * @param index Індекс автомобіля для видалення.
 */
void removeCar(CarList *list, size_t index) {
    if (index < list->size) {
        for (size_t i = index; i < list->size - 1; ++i) {
            list->data[i] = list->data[i + 1];
        }
        list->size--;
    }
}

/**
 * @brief Виводить список автомобілів на екран.
 * @param list Вказівник на CarList.
 */
void printList(const CarList *list) {
    for (size_t i = 0; i < list->size; ++i) {
        printf("Brand: %s, Model: %s, Year: %d, Price: %.2f\n",
               list->data[i].brand, list->data[i].model,
               list->data[i].year, list->data[i].price);
    }
}

/**
 * @brief Порівнює два автомобілі за ціною.
 * @param a Вказівник на перший автомобіль.
 * @param b Вказівник на другий автомобіль.
 * @return Результат порівняння.
 */
int compareByPrice(const void *a, const void *b) {
    Car *carA = (Car *)a;
    Car *carB = (Car *)b;
    return (carA->price > carB->price) - (carA->price < carB->price);
}

/**
 * @brief Сортує автомобілі за ціною.
 * @param list Вказівник на CarList.
 */
void sortListByPrice(CarList *list) {
    qsort(list->data, list->size, sizeof(Car), compareByPrice);
}

/**
 * @brief Шукає автомобілі за маркою.
 * @param list Вказівник на CarList.
 * @param brand Марка автомобіля для пошуку.
 */
void searchByBrand(const CarList *list, const char *brand) {
    for (size_t i = 0; i < list->size; ++i) {
        if (strcmp(list->data[i].brand, brand) == 0) {
            printf("Brand: %s, Model: %s, Year: %d, Price: %.2f\n",
                   list->data[i].brand, list->data[i].model,
                   list->data[i].year, list->data[i].price);
        }
    }
}
