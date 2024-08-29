#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

#define BUFFER_SIZE 256

int main() {
    int n;
    char buffer[BUFFER_SIZE];


    write(STDOUT_FILENO, "Лабораторна робота №11. Взаємодія з користувачем шляхом механізму введення/виведення\n", 159);
    write(STDOUT_FILENO, "Введіть розмір квадратної матриці: ", 66);
    read(STDIN_FILENO, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &n);

    if (n <= 0) {
        write(STDOUT_FILENO, "Некоректний ввід. Розмір квадратної матриці повинен бути додатнім числом.\n", 138);
        return 1;
    }
    double **matrix = create_matrix(n); 

    write(STDOUT_FILENO, "Введіть елементи матриці ", 48);
    sprintf(buffer, "%d", n);
    write(STDOUT_FILENO, buffer, BUFFER_SIZE);
    write(STDOUT_FILENO, " x ", 3);
    write(STDOUT_FILENO, buffer, BUFFER_SIZE);
    write(STDOUT_FILENO, ":\n", 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            read(STDIN_FILENO, buffer, BUFFER_SIZE);
            sscanf(buffer, "%lf", &matrix[i][j]);
        }
        fflush(stdin); 
    }


    write(STDOUT_FILENO, "Квадратна матриця:\n", 36);
    print_matrix(matrix, n);

    double **inverse_matrix = inverse(matrix, n); 
    if (inverse_matrix != NULL) {
        write(STDOUT_FILENO, "Зворотня матриця:\n", 34);
        print_matrix(inverse_matrix, n); 
        free_matrix(inverse_matrix, n); 
    }

    free_matrix(matrix, n); 

    return 0;
}