#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

/**
 * @brief Головна функція програми
 * 
 * @param argc Кількість аргументів командного рядка
 * @param argv Масив аргументів командного рядка
 * @return int Статус виконання програми
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    Car cars[100];
    int count;

    readData(argv[1], cars, &count);
    printData(cars, count);

    printf("\nSearching for brand 'Ford':\n");
    searchByBrand(cars, count, "Ford");

    printf("\nSorting cars by price:\n");
    sortCarsByPrice(cars, count);
    printData(cars, count);

    writeDataBinary("cars.bin", cars, count);
    Car carsFromBinary[100];
    int countFromBinary;
    readDataBinary("cars.bin", carsFromBinary, &countFromBinary);
    printf("\nData read from binary file:\n");
    printData(carsFromBinary, countFromBinary);

    return 0;
}
