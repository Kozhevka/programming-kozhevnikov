
#include <stdio.h>
int numberInput(const char* message);
int calculateSumInRange(int a, int b);


int main()
{
    int number1, number2;

    number1 = numberInput("Введіть перше число: ");
    number2 = numberInput("Введіть друге число: ");

    int start;
    int end;

    if (number1 > number2)
    {
        start = number2;
        end = number1;
    } else
    {
        end = number2;
        start = number1;
    }

    int result = calculateSumInRange(start, end);
    
    printf("Сума чисел у діапазоні від %d до %d, дорівнює: %d\n", start, end, result);
    return 0;
}

int numberInput(const char* message)
{
    int result;

    int success = 0;

    while (!success) {
        printf("%s", message);
        if (scanf("%d", &result) == 1) {
            success = 1;
        } else {
            printf("Помилка формату! Введіть коректне число.\n");
            while (getchar() != '\n');
        }
    }

    return result;
}

int calculateSumInRange(int a, int b)
{
    return (a+b) * (b-a+1)/2;
}
