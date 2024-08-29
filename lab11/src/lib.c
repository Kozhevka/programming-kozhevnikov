#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

double **create_matrix(int n) 
{
    double **matrix = (double **)malloc(n * sizeof(double *));
    if (matrix == NULL) 
    {
        printf("Помилка виділення пам'яті для матриці.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = (double *)malloc(n * sizeof(double));
        if (matrix[i] == NULL) 
        {
            printf("Помилка виділення пам'яті для рядка матриці.\n");
            exit(1);
        }
    }
    return matrix;
}

void free_matrix(double **matrix, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(double **matrix, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

double determinant(double **matrix, int n) 
{
    if (n == 1) 
    {
        return matrix[0][0];
    }
    double det = 0.0;
    double **submatrix = create_matrix(n - 1);
    int sign = 1;
    for (int j = 0; j < n; j++) 
    {
        int sub_i = 0;
        for (int row = 1; row < n; row++) 
        {
            int sub_j = 0;
            for (int col = 0; col < n; col++) 
            {
                if (col != j) 
                {
                    submatrix[sub_i][sub_j] = matrix[row][col];
                    sub_j++;
                }
            }
            sub_i++;
        }
        det += sign * matrix[0][j] * determinant(submatrix, n - 1);
        sign = -sign;
    }
    free_matrix(submatrix, n - 1);
    return det;
}

double **inverse(double **matrix, int n) 
{
    double det = determinant(matrix, n);
    if (det == 0.0) 
    {
        printf("Матриця є сингулярною (детермінант дорівнює нулю) і не може бути оберненою.\n");
        return NULL;
    }

    double **augmented_matrix = create_matrix(n);
    for (int i = 0; i < n; i++) 
    {
        augmented_matrix[i] = (double *)malloc(2 * n * sizeof(double));
        if (augmented_matrix[i] == NULL) 
        {
            printf("Помилка виділення пам'яті для рядка посилених матриці.\n");
            exit(1);
        }
        for (int j = 0; j < n; j++) 
        {
            augmented_matrix[i][j] = matrix[i][j];
            augmented_matrix[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }


    for (int i = 0; i < n; i++) 
    {

        int max_row = i;
        for (int k = i + 1; k < n; k++) 
        {
            if (fabs(augmented_matrix[k][i]) > fabs(augmented_matrix[max_row][i])) 
            {
                max_row = k;
            }
        }

        if (max_row != i) 
        {
            double *temp = augmented_matrix[i];
            augmented_matrix[i] = augmented_matrix[max_row];
            augmented_matrix[max_row] = temp;
        }

        for (int k = i + 1; k < n; k++) 
        {
            double factor = augmented_matrix[k][i] / augmented_matrix[i][i];
            for (int j = i; j < 2 * n; j++) 
            {
                augmented_matrix[k][j] -= factor * augmented_matrix[i][j];
            }
        }
    }


    for (int i = n - 1; i > 0; i--) 
    {
        for (int k = i - 1; k >= 0; k--) 
        {
            double factor = augmented_matrix[k][i] / augmented_matrix[i][i];
            for (int j = 0; j < 2 * n; j++) 
            {
                augmented_matrix[k][j] -= factor * augmented_matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        double divisor = augmented_matrix[i][i];
        for (int j = 0; j < 2 * n; j++) 
        {
            augmented_matrix[i][j] /= divisor;
        }
    }

    double **inverse_matrix = create_matrix(n);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            inverse_matrix[i][j] = augmented_matrix[i][j + n];
        }
    }

    free_matrix(augmented_matrix, n);
    return inverse_matrix;
}
