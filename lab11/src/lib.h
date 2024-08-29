// lib.h
#ifndef LIB_H
#define LIB_H

double **create_matrix(int n);
void free_matrix(double **matrix, int n);
void print_matrix(double **matrix, int n);
double **inverse(double **matrix, int n);
double determinant(double **matrix, int n);

#endif  /* LIB_H */