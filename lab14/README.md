# Лабораторна робота №14: Структуровані типи даних

## Студент
- **Ім'я:** Кожевніков Ілля Володимирович
- **Група:** КН-923в

## Завдання
Розробити програму, яка працює з масивом структур `Car`. Програма повинна забезпечувати читання даних з файлу, виведення їх на екран, сортування за ціною, пошук за брендом, а також роботу з бінарними файлами.

## Опис програми
Програма складається з таких компонентів:
1. **src/main.c**: Головний файл програми, який містить точку входу `main()` і основну логіку програми.
2. **src/lib.c, src/lib.h**: Файли, які містять функції для роботи з даними. `lib.h` містить прототипи цих функцій, а `lib.c` - їхні реалізації.
3. **test/test.c**: Файл, який містить функції для автоматичного тестування програми.

## Використання програми
1. **Компіляція**: Виконайте команду `make`, щоб скомпілювати проект.
2. **Запуск основної програми**: Використовуйте команду `./lab14 <input file>`, де `<input file>` - це ваш файл з вхідними даними.
```plaintext
Brand: Toyota, Model: Camry, Year: 2010, Price: 15000.00
Brand: Ford, Model: Focus, Year: 2012, Price: 12000.00
Brand: Honda, Model: Civic, Year: 2015, Price: 18000.00
Brand: Toyota, Model: Corolla, Year: 2011, Price: 14000.00
Brand: Ford, Model: Mustang, Year: 2018, Price: 30000.00

Searching for brand 'Ford':
Brand: Ford, Model: Focus, Year: 2012, Price: 12000.00
Brand: Ford, Model: Mustang, Year: 2018, Price: 30000.00

Sorting cars by price:
Brand: Ford, Model: Focus, Year: 2012, Price: 12000.00
Brand: Toyota, Model: Corolla, Year: 2011, Price: 14000.00
Brand: Toyota, Model: Camry, Year: 2010, Price: 15000.00
Brand: Honda, Model: Civic, Year: 2015, Price: 18000.00
Brand: Ford, Model: Mustang, Year: 2018, Price: 30000.00

Data read from binary file:
Brand: Ford, Model: Focus, Year: 2012, Price: 12000.00
Brand: Toyota, Model: Corolla, Year: 2011, Price: 14000.00
Brand: Toyota, Model: Camry, Year: 2010, Price: 15000.00
Brand: Honda, Model: Civic, Year: 2015, Price: 18000.00
Brand: Ford, Model: Mustang, Year: 2018, Price: 30000.00
```

## Важливі зауваження
- Передбачається, що вхідні дані у файлі `input.txt` містять коректні значення для полів `brand`, `model`, `year` та `price`.
- У разі некоректних вхідних даних програма може працювати некоректно або навіть завершитися з помилкою.

## Завершення
Ця програма дозволяє працювати з масивом структур `Car`, забезпечуючи основні функції для читання, запису, сортування та пошуку даних. Вона також підтримує роботу з бінарними файлами для більш ефективного зберігання даних.
