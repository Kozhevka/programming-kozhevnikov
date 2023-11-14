#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int getRandom();

int taskFunction(int number);
int getNumberDigitsCount(int number);

int combineArrayToInt(int* numbersArray, int arraySize);
char * numberToCharArray(int* numbersArray);
int * numberToIntArray(int number, int numberMaxSize);

/// Масиви рядків для словесного представлення чисел
char *units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *hundreds[] = {"hundred", "thousand"};

int main() /// Головна функція
{
#define maxNumbersCount 4

    int number = getRandom();
    printf("Generated random number: %d \n", number);

    int lab7result = taskFunction(number);
    printf("\nCurrent less next iteration count: %d \n", lab7result);

    int *numberArray = numberToIntArray(number, maxNumbersCount); //ініціалізація масиву

    int numberDecimalCount = getNumberDigitsCount(number);
    int generatedPrintableNumber = combineArrayToInt(numberArray, maxNumbersCount);
    char *numberAsString = numberToCharArray(numberArray);

    printf("Randomly generated number %d. \nWrite as: %s \n",generatedPrintableNumber, numberAsString);


    free(numberArray);
    free(numberAsString);
    return 0;
}

int taskFunction(int number) ///Функція, що визначає, скільки серед заданої послідовності чисел таких пар, у котрих перше число менше наступного
{
    int arraySize = getNumberDigitsCount(number);
    int *numberArray = numberToIntArray(number, arraySize);

    int counter = 0;
    int previousNumber = numberArray[0];

    for (int i = 1; i < arraySize; i++)
    {
        if (previousNumber < numberArray[i])
        {
            printf("%d < %d; ", previousNumber, numberArray[i]);
            counter++;
        }
        previousNumber = numberArray[i];
    }

    free(numberArray);
    return counter;
}

int getNumberDigitsCount(int number) /// Get digits count from number
{
    int arraySize = 0;

    int n = number;

    do {
        n /= 10;
        arraySize++;
    } while (n != 0);

    return arraySize;
}


int combineArrayToInt(int* numbersArray, int arraySize) /// Масив чисел перетворити у число
{
    int result = 0;

    int numberSize = 1;

    for (int y = 1; y < arraySize; y++)
    {
        numberSize *= 10;
    }

    for (int i = 0; i < arraySize; i++, numberSize /= 10)
    {
        result += numbersArray[i] * numberSize;
    }
    return result;
}


int getRandom() ///Генерація сіду для  рандому на основі часу (щоб результат random не був завжди однаковий)
{
    srand((unsigned int)time(NULL));

    int result = (int)random();

    return result;
}

int * numberToIntArray(int number, int numberMaxSize) /// get digits array from number.
{
    if (numberMaxSize == 0) //get current number digits count.
    {
        numberMaxSize = getNumberDigitsCount(number);
    }

    int *resultInt = malloc((unsigned long)numberMaxSize * sizeof(int));

    for (int i = numberMaxSize - 1; i >= 0; i--)
    {
        resultInt[i] = number % 10; //Присвоюємо цифру індексу в масиві
        number /= 10;
    }

    return resultInt;
}

char * numberToCharArray(int* numberArray) /// Отримати число у вигляді слів.
{
    char result[100] = ""; // Рядок для зберігання словесного представлення числа


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

    char *resultString = (char *)malloc(100);
    for (int i = 0; i < 100; ++i)
    {
        resultString[i] = result[i];
    }

    return resultString;
}