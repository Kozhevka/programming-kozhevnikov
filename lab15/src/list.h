/**
 * @file list.h
 * @brief Оголошення функцій для роботи з динамічним масивом CarList.
 */

#ifndef LIST_H
#define LIST_H

#include "entity.h"
#include <stddef.h> // Додано для size_t

/**
 * @brief Структура для зберігання динамічного масиву автомобілів.
 */
typedef struct {
    Car *data;       /**< Масив автомобілів. */
    size_t size;     /**< Поточний розмір масиву. */
    size_t capacity; /**< Потужність масиву. */
} CarList;

void initList(CarList *list);
void freeList(CarList *list);
void addCar(CarList *list, Car car);
void removeCar(CarList *list, size_t index);
void printList(const CarList *list);
void sortListByPrice(CarList *list);
void searchByBrand(const CarList *list, const char *brand);

#endif // LIST_H
