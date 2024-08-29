#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

/**
 * @brief Читає дані з текстового файлу
 * 
 * @param filename Ім'я файлу для читання
 * @param cars Масив структур Car
 * @param count Кількість прочитаних записів
 */
void readData(const char *filename, Car *cars, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    *count = 0;
    while (fscanf(file, "%49s %49s %d %lf", cars[*count].brand, cars[*count].model, &cars[*count].year, &cars[*count].price) == 4) {
        (*count)++;
    }
    fclose(file);
}

/**
 * @brief Записує дані у текстовий файл
 * 
 * @param filename Ім'я файлу для запису
 * @param cars Масив структур Car
 * @param count Кількість записів для запису
 */
void writeData(const char *filename, Car *cars, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %d %lf\n", cars[i].brand, cars[i].model, cars[i].year, cars[i].price);
    }
    fclose(file);
}

/**
 * @brief Виводить дані на екран
 * 
 * @param cars Масив структур Car
 * @param count Кількість записів для виведення
 */
void printData(Car *cars, int count) {
    for (int i = 0; i < count; i++) {
        printf("Brand: %s, Model: %s, Year: %d, Price: %.2lf\n", cars[i].brand, cars[i].model, cars[i].year, cars[i].price);
    }
}

/**
 * @brief Шукає автомобілі за маркою
 * 
 * @param cars Масив структур Car
 * @param count Кількість записів
 * @param brand Марка автомобіля для пошуку
 */
void searchByBrand(Car *cars, int count, const char *brand) {
    for (int i = 0; i < count; i++) {
        if (strcmp(cars[i].brand, brand) == 0) {
            printf("Brand: %s, Model: %s, Year: %d, Price: %.2lf\n", cars[i].brand, cars[i].model, cars[i].year, cars[i].price);
        }
    }
}

/**
 * @brief Порівнює два автомобілі за ціною
 * 
 * @param a Вказівник на перший автомобіль
 * @param b Вказівник на другий автомобіль
 * @return int Результат порівняння
 */
int compareByPrice(const void *a, const void *b) {
    Car *carA = (Car *)a;
    Car *carB = (Car *)b;
    return (carA->price > carB->price) - (carA->price < carB->price);
}

/**
 * @brief Сортує автомобілі за ціною
 * 
 * @param cars Масив структур Car
 * @param count Кількість записів для сортування
 */
void sortCarsByPrice(Car *cars, int count) {
    qsort(cars, count, sizeof(Car), compareByPrice);
}

/**
 * @brief Генерує випадковий автомобіль
 * 
 * @param car Вказівник на структуру Car
 * @param variant Варіант генерації
 */
void generateCar(Car *car, int variant) {
    sprintf(car->brand, "Brand%d", rand() % 100);
    sprintf(car->model, "Model%d", rand() % 100);
    car->year = rand() % 20 + 2000;
    car->price = rand() % (variant * 10) + variant;
}

/**
 * @brief Записує дані у бінарний файл
 * 
 * @param filename Ім'я файлу для запису
 * @param cars Масив структур Car
 * @param count Кількість записів для запису
 */
void writeDataBinary(const char *filename, Car *cars, int count) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    fwrite(cars, sizeof(Car), count, file);
    fclose(file);
}

/**
 * @brief Читає дані з бінарного файлу
 * 
 * @param filename Ім'я файлу для читання
 * @param cars Масив структур Car
 * @param count Кількість прочитаних записів
 */
void readDataBinary(const char *filename, Car *cars, int *count) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    *count = 0;
    while (fread(&cars[*count], sizeof(Car), 1, file)) {
        (*count)++;
    }
    fclose(file);
}
