/**
 * @file list.c
 * @brief Реалізація функцій для роботи з односпрямованим списком CarList.
 */

#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Ініціалізує односпрямований список CarList.
 * @param list Вказівник на CarList.
 */
void initList(CarList *list) {
    list->head = NULL;
}

/**
 * @brief Звільняє пам'ять, зайняту списком CarList.
 * @param list Вказівник на CarList.
 */
void freeList(CarList *list) {
    Car *current = list->head;
    while (current != NULL) {
        Car *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

/**
 * @brief Додає новий автомобіль до кінця списку CarList.
 * @param list Вказівник на CarList.
 * @param car Автомобіль для додавання.
 */
void addCar(CarList *list, Car car) {
    Car *newCar = (Car *)malloc(sizeof(Car));
    *newCar = car;
    newCar->next = NULL;

    if (list->head == NULL) {
        list->head = newCar;
    } else {
        Car *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCar;
    }
}

/**
 * @brief Видаляє автомобіль з списку CarList за індексом.
 * @param list Вказівник на CarList.
 * @param index Індекс автомобіля для видалення.
 */
void removeCar(CarList *list, size_t index) {
    if (list->head == NULL) return;

    Car *current = list->head;
    if (index == 0) {
        list->head = current->next;
        free(current);
        return;
    }

    for (size_t i = 0; current != NULL && i < index - 1; ++i) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) return;

    Car *next = current->next->next;
    free(current->next);
    current->next = next;
}

/**
 * @brief Виводить список автомобілів на екран.
 * @param list Вказівник на CarList.
 */
void printList(const CarList *list) {
    Car *current = list->head;
    while (current != NULL) {
        printf("Brand: %s, Model: %s, Year: %d, Price: %.2f\n",
               current->brand, current->model, current->year, current->price);
        current = current->next;
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
    if (list->head == NULL) return;

    int swapped;
    Car *ptr1;
    Car *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = list->head;

        while (ptr1->next != lptr) {
            if (ptr1->price > ptr1->next->price) {
                Car temp = *ptr1;
                ptr1->price = ptr1->next->price;
                ptr1->next->price = temp.price;

                char tempBrand[50], tempModel[50];
                int tempYear;

                strcpy(tempBrand, ptr1->brand);
                strcpy(tempModel, ptr1->model);
                tempYear = ptr1->year;

                strcpy(ptr1->brand, ptr1->next->brand);
                strcpy(ptr1->model, ptr1->next->model);
                ptr1->year = ptr1->next->year;

                strcpy(ptr1->next->brand, tempBrand);
                strcpy(ptr1->next->model, tempModel);
                ptr1->next->year = tempYear;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/**
 * @brief Шукає автомобілі за маркою.
 * @param list Вказівник на CarList.
 * @param brand Марка автомобіля для пошуку.
 */
void searchByBrand(const CarList *list, const char *brand) {
    Car *current = list->head;
    while (current != NULL) {
        if (strcmp(current->brand, brand) == 0) {
            printf("Brand: %s, Model: %s, Year: %d, Price: %.2f\n",
                   current->brand, current->model, current->year, current->price);
        }
        current = current->next;
    }
}

/**
 * @brief Читає список автомобілів з файлу.
 * @param list Вказівник на CarList.
 * @param filename Ім'я файлу для читання.
 */
void readFromFile(CarList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file for reading");
        return;
    }

    Car car;
    while (fscanf(file, "%49s %49s %d %lf", car.brand, car.model, &car.year, &car.price) == 4) {
        addCar(list, car);
    }

    fclose(file);
}

/**
 * @brief Записує список автомобілів у файл.
 * @param list Вказівник на CarList.
 * @param filename Ім'я файлу для запису.
 */
void writeToFile(const CarList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    Car *current = list->head;
    while (current != NULL) {
        fprintf(file, "%s %s %d %.2f\n", current->brand, current->model, current->year, current->price);
        current = current->next;
    }

    fclose(file);
}
