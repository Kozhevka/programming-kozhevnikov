#ifndef LIB_H
#define LIB_H

/**
 * @brief Структура, що представляє автомобіль
 */
typedef struct {
    char brand[50];   /**< Марка автомобіля */
    char model[50];   /**< Модель автомобіля */
    int year;         /**< Рік випуску автомобіля */
    double price;     /**< Ціна автомобіля */
} Car;

/**
 * @brief Читає дані з текстового файлу
 * 
 * @param filename Ім'я файлу для читання
 * @param cars Масив структур Car
 * @param count Кількість прочитаних записів
 */
void readData(const char *filename, Car *cars, int *count);

/**
 * @brief Записує дані у текстовий файл
 * 
 * @param filename Ім'я файлу для запису
 * @param cars Масив структур Car
 * @param count Кількість записів для запису
 */
void writeData(const char *filename, Car *cars, int count);

/**
 * @brief Виводить дані на екран
 * 
 * @param cars Масив структур Car
 * @param count Кількість записів для виведення
 */
void printData(Car *cars, int count);

/**
 * @brief Шукає автомобілі за маркою
 * 
 * @param cars Масив структур Car
 * @param count Кількість записів
 * @param brand Марка автомобіля для пошуку
 */
void searchByBrand(Car *cars, int count, const char *brand);

/**
 * @brief Сортує автомобілі за ціною
 * 
 * @param cars Масив структур Car
 * @param count Кількість записів для сортування
 */
void sortCarsByPrice(Car *cars, int count);

/**
 * @brief Генерує випадковий автомобіль
 * 
 * @param car Вказівник на структуру Car
 * @param variant Варіант генерації
 */
void generateCar(Car *car, int variant);

/**
 * @brief Записує дані у бінарний файл
 * 
 * @param filename Ім'я файлу для запису
 * @param cars Масив структур Car
 * @param count Кількість записів для запису
 */
void writeDataBinary(const char *filename, Car *cars, int count);

/**
 * @brief Читає дані з бінарного файлу
 * 
 * @param filename Ім'я файлу для читання
 * @param cars Масив структур Car
 * @param count Кількість прочитаних записів
 */
void readDataBinary(const char *filename, Car *cars, int *count);

#endif // LIB_H
