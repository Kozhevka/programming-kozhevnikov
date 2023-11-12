#include <stdio.h>
#include <stdlib.h>


int numberInput(const char* message);

// Масиви рядків для словесного представлення чисел
char *units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *hundreds[] = {"hundred", "thousand"};



int main() {
    int number;

    // Введення числа
    number =  numberInput("Введіть число в межах від 0 до 9999: ");

    int n = number; //копіюємо число для математичних операцій

    int numberArray[4];

    n = number;

    //Присвоїти число кожному індексу

    for (int i = 3; i >= 0; i--)
    {
        numberArray[i] = n % 10; //Присвоюємо цифру індексу в масиві
        n /= 10;
    }

    char result[50] = ""; // Рядок для зберігання словесного представлення числа


    if (numberArray[0] != 0) // Якщо у числі є тисячі
    {
        sprintf(result, "%s %s" , units[numberArray[0]], hundreds[1]);
    }

    if (numberArray[1] != 0) //Якщо у числі є сотні
    {
        sprintf(result, "%s %s %s", result, units[numberArray[1]], hundreds[0]);
    }

    if (numberArray[2] >= 2) //Якщо десятки більше 20ти включно
    {
        sprintf(result, "%s %s %s" , result , tens[numberArray[2]], units[numberArray[3]]);
    }
    else
    {
        if (numberArray[2] * 10 + numberArray[3] > 10) // Якщо десятки в межах 11-19
        {
            sprintf(result, "%s %s" , result , teens[numberArray[3]]);
        } else // немає десятків
        {
            sprintf(result, "%s %s" , result , units[numberArray[3]]);
        }
    }

    printf("%s\n", result);
    return 0;
}

int numberInput(const char* message)
{
    int result;

    int success = 0;

    while (!success) {
        printf("%s", message);
        if (scanf("%d", &result) == 1)
        {
            if (result > 9999 || result < 0)
            {
                printf("Помилка умов! Введіть число в межах від 0 до 9999:\n");
                continue;
            }
            success = 1;
        }
        else
        {
            printf("Помилка формату! Введіть коректне число.\n");
            while (getchar() != '\n');
        }
    }

    return result;
}