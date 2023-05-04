#ifndef MATRIX_SRC_HEADERS_MY_MATRIX_H_
#define MATRIX_SRC_HEADERS_MY_MATRIX_H_

#include <math.h>
#include <stdlib.h>

#define EPS 1e-07

typedef enum CodeErrors { OK, INPUT_ERROR, CALC_ERROR } CodeErrors;

typedef enum Bool { FALSE, TRUE } Bool;

typedef enum Validation { FAILURE, SUCCESS } Validation;

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

int my_create_matrix(int rows, int columns, matrix_t* result);
void my_remove_matrix(matrix_t* A);
int my_eq_matrix(matrix_t* A, matrix_t* B);
int my_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int my_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int my_mult_number(matrix_t* A, double number, matrix_t* result);
int my_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int my_transpose(matrix_t* A, matrix_t* result);
int my_determinant(matrix_t* A, double* result);
int my_calc_complements(matrix_t* A, matrix_t* result);
int my_inverse_matrix(matrix_t* A, matrix_t* result);

#endif  // MATRIX_SRC_HEADERS_MY_MATRIX_H_
