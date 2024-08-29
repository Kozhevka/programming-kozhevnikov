#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/lib.h"

/**
 * @brief Тестова функція для перевірки роботи бібліотеки
 * 
 * @return int Статус виконання тесту
 */

void test() {
    Car cars[5];
    int count = 5;
    

    strcpy(cars[0].brand, "Toyota");
    strcpy(cars[0].model, "Camry");
    cars[0].year = 2010;
    cars[0].price = 15000.00;
    
    strcpy(cars[1].brand, "Ford");
    strcpy(cars[1].model, "Focus");
    cars[1].year = 2012;
    cars[1].price = 12000.00;
    
    strcpy(cars[2].brand, "Honda");
    strcpy(cars[2].model, "Civic");
    cars[2].year = 2015;
    cars[2].price = 18000.00;
    
    strcpy(cars[3].brand, "Toyota");
    strcpy(cars[3].model, "Corolla");
    cars[3].year = 2011;
    cars[3].price = 14000.00;
    
    strcpy(cars[4].brand, "Ford");
    strcpy(cars[4].model, "Mustang");
    cars[4].year = 2018;
    cars[4].price = 30000.00;
    

    writeData("test_output.txt", cars, count);
    

    Car readCars[5];
    int readCount;
    readData("test_output.txt", readCars, &readCount);

    printf("\nData read from text file:\n");
    printData(readCars, readCount);

    sortCarsByPrice(cars, count);
    printf("\nCars sorted by price:\n");
    printData(cars, count);

    printf("\nSearching for brand 'Ford':\n");
    searchByBrand(cars, count, "Ford");
    
    writeDataBinary("test_output.bin", cars, count);
    Car readCarsBinary[5];
    int readCountBinary;
    readDataBinary("test_output.bin", readCarsBinary, &readCountBinary);
    
    printf("\nData read from binary file:\n");
    printData(readCarsBinary, readCountBinary);
}

int main() {
    test();
    return 0;
}
