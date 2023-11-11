#include <stdio.h>
#include <math.h>

double doubleNumberInput(const char* message);

char calculationTypeInput();
void calculateLengthOfCircle(double radius);
void calculateAreaOfCircle(double radius);
void calculateVolumeOfTheSphere(double radius);


int main() {

    double radius;
    char command;

    radius = doubleNumberInput("Введіть радіус: ");

    command = calculationTypeInput();

    // Обчислення та виведення результату відповідно до команди
    switch (command) {
        case 'l':
            calculateLengthOfCircle(radius);
            break;
        case 's':
            calculateAreaOfCircle(radius);
            break;
        case 'v':
            calculateVolumeOfTheSphere(radius);
            break;
        default:
            printf("Невірна команда. Помилка у перевірці значення.\n");
            break;
    }

    return 0;
}



double doubleNumberInput(const char* message)
{
    double result;

    int success = 0;

    while (!success) {
        printf("%s", message);
        if (scanf("%lf", &result) == 1) {
            success = 1;
        } else {
            printf("Помилка формату! Введіть коректне число з плаваючою точкою.\n");
            while (getchar() != '\n');
        }
    }

    return result;
}

char calculationTypeInput()
{
    char command;

    int validInput = 0;
    while (!validInput)
    {
        printf("Введіть команду ('l' - довжина, 's' - площа, 'v' - об'єм): ");
        if (scanf(" %c", &command) == 1)
        {
            if (command == 'l' || command == 's' || command == 'v')
            {
                validInput = 1;
            }
            else
            {
                printf("Невірна команда. Введіть 'l', 's' або 'v'.\n");
            }
        }
        else
        {
            printf("Помилка формату! Введіть один символ.\n");
            while (getchar() != '\n');  // Очищення буфера введення
        }
    }

    return command;
}

void calculateLengthOfCircle(double radius)
{
    double lenght;

    lenght = 2 * M_PI * radius;

    printf("Довжина окружності: %lf\n", lenght);

    return;
}

void calculateAreaOfCircle(double radius)
{
    double area;

    area = M_PI * radius * radius;

    printf("Площа кола: %lf\n", area);

    return;
}

void calculateVolumeOfTheSphere(double radius)
{
    double volume;

    volume = (4.0 / 3.0) * M_PI * (radius * radius * radius);

    printf("Об'єм кулі: %lf\n", volume);

    return;
}