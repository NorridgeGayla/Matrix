#ifndef MATRIX_SRC_HEADERS_EXTRA_H_
#define MATRIX_SRC_HEADERS_EXTRA_H_

#include "../headers/my_matrix.h"

int check_matrix(matrix_t *T);
int get_minor(matrix_t *T, int delete_row, int delete_column, matrix_t *result);

void input_matrix(matrix_t *T);
void print_matrix(matrix_t *T);

#endif  // MATRIX_SRC_HEADERS_EXTRA_H_
