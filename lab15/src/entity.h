/**
 * @file entity.h
 * @brief Опис структури Car.
 */

#ifndef ENTITY_H
#define ENTITY_H

/**
 * @brief Структура для зберігання інформації про автомобіль.
 */
typedef struct {
    char brand[50]; /**< Марка автомобіля. */
    char model[50]; /**< Модель автомобіля. */
    int year;       /**< Рік випуску автомобіля. */
    double price;   /**< Ціна автомобіля. */
} Car;

#endif // ENTITY_H
