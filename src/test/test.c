/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "test.check" instead.
 */

#include <check.h>
#include <stdio.h>

#include "../headers/my_matrix.h"

// my_create_matrix

START_TEST(my_create_matrix_1) {
  matrix_t *matrix = NULL;
  int rows = 1;
  int columns = 1;
  ck_assert_int_eq(my_create_matrix(rows, columns, matrix), INPUT_ERROR);
}
END_TEST

START_TEST(my_create_matrix_2) {
  matrix_t matrix = {0};
  int rows = 0;
  int columns = 1;
  ck_assert_int_eq(my_create_matrix(rows, columns, &matrix), INPUT_ERROR);
}
END_TEST

START_TEST(my_create_matrix_3) {
  matrix_t matrix = {0};
  int rows = 1;
  int columns = -1;
  ck_assert_int_eq(my_create_matrix(rows, columns, &matrix), INPUT_ERROR);
}
END_TEST

START_TEST(my_create_matrix_4) {
  matrix_t *matrix = NULL;
  int rows = 0;
  int columns = -1;
  ck_assert_int_eq(my_create_matrix(rows, columns, matrix), INPUT_ERROR);
}
END_TEST

START_TEST(my_create_matrix_5) {
  matrix_t A = {0};
  int rows = 3;
  int columns = 3;
  ck_assert_int_eq(my_create_matrix(rows, columns, &A), OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(A.matrix[i][j], 0);
    }
  }
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_create_matrix_6) {
  matrix_t A = {0};
  int rows = 10;
  int columns = 12;
  ck_assert_int_eq(my_create_matrix(rows, columns, &A), OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq(A.matrix[i][j], 0);
    }
  }
  my_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);

  // my_create_matrix
}
END_TEST

START_TEST(my_eq_matrix_1) {
  matrix_t *A = NULL;
  matrix_t B = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(my_eq_matrix(A, &B), FAILURE);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_2) {
  matrix_t A = {0};
  matrix_t *B = NULL;
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_eq_matrix(&A, B), FAILURE);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_eq_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(my_eq_matrix(&A, &B), SUCCESS);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 10;
  my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(my_eq_matrix(&A, &B), FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows + 1, columns, &B);
  ck_assert_int_eq(my_eq_matrix(&A, &B), FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns - 1, &B);
  ck_assert_int_eq(my_eq_matrix(&A, &B), FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows + 1, columns - 1, &B);
  ck_assert_int_eq(my_eq_matrix(&A, &B), FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_eq_matrix_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1.12345678;
  my_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 1.12345677;
  ck_assert_int_eq(my_eq_matrix(&A, &B), SUCCESS);
  my_remove_matrix(&A);
  my_remove_matrix(&B);

  // my_sum_matrix
}
END_TEST

START_TEST(my_sum_matrix_1) {
  matrix_t *A = NULL;
  matrix_t B = {0};
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(my_sum_matrix(A, &B, &res), INPUT_ERROR);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sum_matrix_2) {
  matrix_t A = {0};
  matrix_t *B = NULL;
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_sum_matrix(&A, B, &res), INPUT_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_sum_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t *res = NULL;
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(my_sum_matrix(&A, &B, res), INPUT_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sum_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows + 1, columns, &B);
  ck_assert_int_eq(my_sum_matrix(&A, &B, &res), CALC_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sum_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns + 1, &B);
  ck_assert_int_eq(my_sum_matrix(&A, &B, &res), CALC_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sum_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  int rows = 3;
  int columns = 3;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  my_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 4;
  B.matrix[2][2] = 1;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 2;
  check.matrix[0][1] = 2;
  check.matrix[0][2] = 3;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 4;
  check.matrix[1][2] = 5;
  check.matrix[2][0] = 3;
  check.matrix[2][1] = 4;
  check.matrix[2][2] = 7;
  ck_assert_int_eq(my_sum_matrix(&A, &B, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, rows);
  ck_assert_int_eq(res.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  my_remove_matrix(&check);
}
END_TEST

START_TEST(my_sum_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = 2.4;
  A.matrix[1][0] = 0.11;
  A.matrix[1][1] = 4.004;
  my_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 2.1;
  check.matrix[0][1] = 2.4;
  check.matrix[1][0] = 2.11;
  check.matrix[1][1] = 4.004;
  ck_assert_int_eq(my_sum_matrix(&A, &B, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, rows);
  ck_assert_int_eq(res.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  my_remove_matrix(&check);

  // my_sub_matrix
}
END_TEST

START_TEST(my_sub_matrix_1) {
  matrix_t *A = NULL;
  matrix_t B = {0};
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(my_sub_matrix(A, &B, &res), INPUT_ERROR);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sub_matrix_2) {
  matrix_t A = {0};
  matrix_t *B = NULL;
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_sub_matrix(&A, B, &res), INPUT_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_sub_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t *res = NULL;
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(my_sub_matrix(&A, &B, res), INPUT_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sub_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows + 1, columns, &B);
  ck_assert_int_eq(my_sub_matrix(&A, &B, &res), CALC_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sub_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns + 1, &B);
  ck_assert_int_eq(my_sub_matrix(&A, &B, &res), CALC_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_sub_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  int rows = 3;
  int columns = 3;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  my_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 4;
  B.matrix[2][2] = 1;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 0;
  check.matrix[0][1] = 2;
  check.matrix[0][2] = 3;
  check.matrix[1][0] = -2;
  check.matrix[1][1] = 4;
  check.matrix[1][2] = 5;
  check.matrix[2][0] = -3;
  check.matrix[2][1] = -4;
  check.matrix[2][2] = 5;
  ck_assert_int_eq(my_sub_matrix(&A, &B, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, rows);
  ck_assert_int_eq(res.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  my_remove_matrix(&check);
}
END_TEST

START_TEST(my_sub_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = 2.4;
  A.matrix[1][0] = 0.11;
  A.matrix[1][1] = 4.004;
  my_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 0.1;
  check.matrix[0][1] = 2.4;
  check.matrix[1][0] = -1.89;
  check.matrix[1][1] = 4.004;
  ck_assert_int_eq(my_sub_matrix(&A, &B, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, rows);
  ck_assert_int_eq(res.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  my_remove_matrix(&check);

  // my_mult_number
}
END_TEST

START_TEST(my_mult_number_1) {
  matrix_t *A = NULL;
  matrix_t res = {0};
  double number = 10.0;
  ck_assert_int_eq(my_mult_number(A, number, &res), INPUT_ERROR);
}
END_TEST

START_TEST(my_mult_number_2) {
  matrix_t A = {0};
  matrix_t *res = NULL;
  double number = 10.0;
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_mult_number(&A, number, res), INPUT_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_mult_number_3) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  double number = 2.0;
  int rows = 3;
  int columns = 3;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 4;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 2;
  check.matrix[0][1] = 4;
  check.matrix[0][2] = 6;
  check.matrix[1][0] = 0;
  check.matrix[1][1] = 8;
  check.matrix[1][2] = 4;
  check.matrix[2][0] = 4;
  check.matrix[2][1] = 6;
  check.matrix[2][2] = 8;
  ck_assert_int_eq(my_mult_number(&A, number, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, rows);
  ck_assert_int_eq(res.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&check);
}
END_TEST

START_TEST(my_mult_number_4) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  double number = 0.1;
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1.003;
  A.matrix[0][1] = 0.12;
  A.matrix[1][0] = -100.3;
  A.matrix[1][1] = -4.55;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 0.1003;
  check.matrix[0][1] = 0.012;
  check.matrix[1][0] = -10.03;
  check.matrix[1][1] = -0.455;
  ck_assert_int_eq(my_mult_number(&A, number, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, rows);
  ck_assert_int_eq(res.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&check);

  // my_mult_matrix
}
END_TEST

START_TEST(my_mult_matrix_1) {
  matrix_t *A = NULL;
  matrix_t B = {0};
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(my_mult_matrix(A, &B, &res), INPUT_ERROR);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_mult_matrix_2) {
  matrix_t A = {0};
  matrix_t *B = NULL;
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_mult_matrix(&A, B, &res), INPUT_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_mult_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t *res = NULL;
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(my_mult_matrix(&A, &B, res), INPUT_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_mult_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns + 1, &A);
  my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(my_mult_matrix(&A, &B, &res), CALC_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_mult_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows + 1, columns, &B);
  ck_assert_int_eq(my_mult_matrix(&A, &B, &res), CALC_ERROR);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(my_mult_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  int rows = 3;
  int columns = 3;
  my_create_matrix(rows, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  my_create_matrix(2, columns, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 9;
  check.matrix[0][1] = 11;
  check.matrix[0][2] = 17;
  check.matrix[1][0] = 12;
  check.matrix[1][1] = 13;
  check.matrix[1][2] = 22;
  check.matrix[2][0] = 15;
  check.matrix[2][1] = 15;
  check.matrix[2][2] = 27;
  ck_assert_int_eq(my_mult_matrix(&A, &B, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, rows);
  ck_assert_int_eq(res.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  my_remove_matrix(&check);
}
END_TEST

START_TEST(my_mult_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -1.1;
  A.matrix[0][1] = 5.2;
  A.matrix[1][0] = -3.02;
  A.matrix[1][1] = 0;
  my_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 2.5;
  B.matrix[0][1] = 0.33;
  B.matrix[1][0] = -18.21;
  B.matrix[1][1] = -5.203;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = -97.442;
  check.matrix[0][1] = -27.4186;
  check.matrix[1][0] = -7.55;
  check.matrix[1][1] = -0.9966;
  ck_assert_int_eq(my_mult_matrix(&A, &B, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, rows);
  ck_assert_int_eq(res.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&res);
  my_remove_matrix(&check);

  // my_transpose
}
END_TEST

START_TEST(my_transpose_1) {
  matrix_t *A = NULL;
  matrix_t res = {0};
  ck_assert_int_eq(my_transpose(A, &res), INPUT_ERROR);
}
END_TEST

START_TEST(my_transpose_2) {
  matrix_t A = {0};
  matrix_t *res = NULL;
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_transpose(&A, res), INPUT_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_transpose_3) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  int rows = 3;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  my_create_matrix(columns, rows, &check);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = 2;
  check.matrix[0][2] = 3;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = 5;
  check.matrix[1][2] = 6;
  ck_assert_int_eq(my_transpose(&A, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, columns);
  ck_assert_int_eq(res.columns, rows);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&check);
}
END_TEST

START_TEST(my_transpose_4) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -1.1;
  A.matrix[0][1] = 5.2;
  A.matrix[1][0] = -3.02;
  A.matrix[1][1] = 0;
  my_create_matrix(columns, rows, &check);
  check.matrix[0][0] = -1.1;
  check.matrix[0][1] = -3.02;
  check.matrix[1][0] = 5.2;
  check.matrix[1][1] = 0;
  ck_assert_int_eq(my_transpose(&A, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, columns);
  ck_assert_int_eq(res.columns, rows);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&check);
}
END_TEST

START_TEST(my_transpose_5) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t check = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -1.1;
  my_create_matrix(columns, rows, &check);
  check.matrix[0][0] = -1.1;
  ck_assert_int_eq(my_transpose(&A, &res), OK);
  ck_assert_int_eq(my_eq_matrix(&res, &check), SUCCESS);
  ck_assert_int_eq(res.rows, columns);
  ck_assert_int_eq(res.columns, rows);
  my_remove_matrix(&A);
  my_remove_matrix(&res);
  my_remove_matrix(&check);

  // my_determinant
}
END_TEST

START_TEST(my_determinant_1) {
  matrix_t *A = NULL;
  double result = 0.0;
  ck_assert_int_eq(my_determinant(A, &result), INPUT_ERROR);
}
END_TEST

START_TEST(my_determinant_2) {
  matrix_t A = {0};
  double *result = NULL;
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_determinant(&A, result), INPUT_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_3) {
  matrix_t A = {0};
  double result = 0.0;
  int rows = 2;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_determinant(&A, &result), CALC_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_4) {
  matrix_t A = {0};
  double result = 0.0;
  int rows = 1;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_determinant(&A, &result), CALC_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_5) {
  matrix_t A = {0};
  double result = 0.0;
  double check = 0.0;
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_determinant(&A, &result), OK);
  ck_assert_double_eq(result, check);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_6) {
  matrix_t A = {0};
  double result = 0.0;
  double check = 15.704;
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -1.1;
  A.matrix[0][1] = 5.2;
  A.matrix[1][0] = -3.02;
  A.matrix[1][1] = 0;
  ck_assert_int_eq(my_determinant(&A, &result), OK);
  ck_assert_double_eq(result, check);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_7) {
  matrix_t A = {0};
  double result = 0.0;
  double check = 0.0;
  int rows = 3;
  int columns = 3;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  ck_assert_int_eq(my_determinant(&A, &result), OK);
  ck_assert_double_eq(result, check);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_determinant_8) {
  matrix_t A = {0};
  double result = 0.0;
  double check = -19.49979064;
  int rows = 4;
  int columns = 4;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -1.1;
  A.matrix[0][1] = 5.2;
  A.matrix[0][2] = 10.36;
  A.matrix[0][3] = 0;
  A.matrix[1][0] = -3.02;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = -2.3;
  A.matrix[1][3] = 1.88;
  A.matrix[2][0] = 0.03;
  A.matrix[2][1] = 6.99;
  A.matrix[2][2] = -5.32;
  A.matrix[2][3] = -13.25;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0.04;
  A.matrix[3][2] = -0.006;
  A.matrix[3][3] = 0;
  ck_assert_int_eq(my_determinant(&A, &result), OK);
  ck_assert_double_lt(fabs(result - check), EPS);
  my_remove_matrix(&A);

  // my_calc_complements
}
END_TEST

START_TEST(my_calc_complements_1) {
  matrix_t *A = NULL;
  matrix_t result = {0};
  ck_assert_int_eq(my_calc_complements(A, &result), INPUT_ERROR);
}
END_TEST

START_TEST(my_calc_complements_2) {
  matrix_t A = {0};
  matrix_t *result = NULL;
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_calc_complements(&A, result), INPUT_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_calc_complements_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_calc_complements(&A, &result), CALC_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_calc_complements_4) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 1;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_calc_complements(&A, &result), CALC_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_calc_complements_5) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1.1;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 1;
  ck_assert_int_eq(my_calc_complements(&A, &result), OK);
  ck_assert_int_eq(my_eq_matrix(&result, &check), SUCCESS);
  ck_assert_int_eq(result.rows, rows);
  ck_assert_int_eq(result.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&result);
  my_remove_matrix(&check);
}
END_TEST

START_TEST(my_calc_complements_6) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int rows = 2;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 1;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = -2;
  check.matrix[1][0] = -2;
  check.matrix[1][1] = 4;
  ck_assert_int_eq(my_calc_complements(&A, &result), OK);
  ck_assert_int_eq(my_eq_matrix(&result, &check), SUCCESS);
  ck_assert_int_eq(result.rows, rows);
  ck_assert_int_eq(result.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&result);
  my_remove_matrix(&check);
}
END_TEST

START_TEST(my_calc_complements_7) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int rows = 3;
  int columns = 3;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;
  ck_assert_int_eq(my_calc_complements(&A, &result), OK);
  ck_assert_int_eq(my_eq_matrix(&result, &check), SUCCESS);
  ck_assert_int_eq(result.rows, rows);
  ck_assert_int_eq(result.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&result);
  my_remove_matrix(&check);

  // my_inverse_matrix
}
END_TEST

START_TEST(my_inverse_matrix_1) {
  matrix_t *A = NULL;
  matrix_t result = {0};
  ck_assert_int_eq(my_inverse_matrix(A, &result), INPUT_ERROR);
}
END_TEST

START_TEST(my_inverse_matrix_2) {
  matrix_t A = {0};
  matrix_t *result = NULL;
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_inverse_matrix(&A, result), INPUT_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_inverse_matrix_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 2;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_inverse_matrix(&A, &result), CALC_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_inverse_matrix_4) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 1;
  int columns = 2;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_inverse_matrix(&A, &result), CALC_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_inverse_matrix_5) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(my_inverse_matrix(&A, &result), CALC_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_inverse_matrix_6) {
  matrix_t A = {0};
  matrix_t result = {0};
  int rows = 3;
  int columns = 3;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  ck_assert_int_eq(my_inverse_matrix(&A, &result), CALC_ERROR);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(my_inverse_matrix_7) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int rows = 1;
  int columns = 1;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 0.5;
  ck_assert_int_eq(my_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(my_eq_matrix(&result, &check), SUCCESS);
  ck_assert_int_eq(result.rows, rows);
  ck_assert_int_eq(result.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&result);
  my_remove_matrix(&check);
}
END_TEST

START_TEST(my_inverse_matrix_8) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int rows = 3;
  int columns = 3;
  my_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  my_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = -1;
  check.matrix[0][2] = 1;
  check.matrix[1][0] = -38;
  check.matrix[1][1] = 41;
  check.matrix[1][2] = -34;
  check.matrix[2][0] = 27;
  check.matrix[2][1] = -29;
  check.matrix[2][2] = 24;
  ck_assert_int_eq(my_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(my_eq_matrix(&result, &check), SUCCESS);
  ck_assert_int_eq(result.rows, rows);
  ck_assert_int_eq(result.columns, columns);
  my_remove_matrix(&A);
  my_remove_matrix(&result);
  my_remove_matrix(&check);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("my_matrix.h tests");
  TCase *tc1_1 = tcase_create("Compare");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, my_create_matrix_1);
  tcase_add_test(tc1_1, my_create_matrix_2);
  tcase_add_test(tc1_1, my_create_matrix_3);
  tcase_add_test(tc1_1, my_create_matrix_4);
  tcase_add_test(tc1_1, my_create_matrix_5);
  tcase_add_test(tc1_1, my_create_matrix_6);
  tcase_add_test(tc1_1, my_eq_matrix_1);
  tcase_add_test(tc1_1, my_eq_matrix_2);
  tcase_add_test(tc1_1, my_eq_matrix_3);
  tcase_add_test(tc1_1, my_eq_matrix_4);
  tcase_add_test(tc1_1, my_eq_matrix_5);
  tcase_add_test(tc1_1, my_eq_matrix_6);
  tcase_add_test(tc1_1, my_eq_matrix_7);
  tcase_add_test(tc1_1, my_eq_matrix_8);
  tcase_add_test(tc1_1, my_sum_matrix_1);
  tcase_add_test(tc1_1, my_sum_matrix_2);
  tcase_add_test(tc1_1, my_sum_matrix_3);
  tcase_add_test(tc1_1, my_sum_matrix_4);
  tcase_add_test(tc1_1, my_sum_matrix_5);
  tcase_add_test(tc1_1, my_sum_matrix_6);
  tcase_add_test(tc1_1, my_sum_matrix_7);
  tcase_add_test(tc1_1, my_sub_matrix_1);
  tcase_add_test(tc1_1, my_sub_matrix_2);
  tcase_add_test(tc1_1, my_sub_matrix_3);
  tcase_add_test(tc1_1, my_sub_matrix_4);
  tcase_add_test(tc1_1, my_sub_matrix_5);
  tcase_add_test(tc1_1, my_sub_matrix_6);
  tcase_add_test(tc1_1, my_sub_matrix_7);
  tcase_add_test(tc1_1, my_mult_number_1);
  tcase_add_test(tc1_1, my_mult_number_2);
  tcase_add_test(tc1_1, my_mult_number_3);
  tcase_add_test(tc1_1, my_mult_number_4);
  tcase_add_test(tc1_1, my_mult_matrix_1);
  tcase_add_test(tc1_1, my_mult_matrix_2);
  tcase_add_test(tc1_1, my_mult_matrix_3);
  tcase_add_test(tc1_1, my_mult_matrix_4);
  tcase_add_test(tc1_1, my_mult_matrix_5);
  tcase_add_test(tc1_1, my_mult_matrix_6);
  tcase_add_test(tc1_1, my_mult_matrix_7);
  tcase_add_test(tc1_1, my_transpose_1);
  tcase_add_test(tc1_1, my_transpose_2);
  tcase_add_test(tc1_1, my_transpose_3);
  tcase_add_test(tc1_1, my_transpose_4);
  tcase_add_test(tc1_1, my_transpose_5);
  tcase_add_test(tc1_1, my_determinant_1);
  tcase_add_test(tc1_1, my_determinant_2);
  tcase_add_test(tc1_1, my_determinant_3);
  tcase_add_test(tc1_1, my_determinant_4);
  tcase_add_test(tc1_1, my_determinant_5);
  tcase_add_test(tc1_1, my_determinant_6);
  tcase_add_test(tc1_1, my_determinant_7);
  tcase_add_test(tc1_1, my_determinant_8);
  tcase_add_test(tc1_1, my_calc_complements_1);
  tcase_add_test(tc1_1, my_calc_complements_2);
  tcase_add_test(tc1_1, my_calc_complements_3);
  tcase_add_test(tc1_1, my_calc_complements_4);
  tcase_add_test(tc1_1, my_calc_complements_5);
  tcase_add_test(tc1_1, my_calc_complements_6);
  tcase_add_test(tc1_1, my_calc_complements_7);
  tcase_add_test(tc1_1, my_inverse_matrix_1);
  tcase_add_test(tc1_1, my_inverse_matrix_2);
  tcase_add_test(tc1_1, my_inverse_matrix_3);
  tcase_add_test(tc1_1, my_inverse_matrix_4);
  tcase_add_test(tc1_1, my_inverse_matrix_5);
  tcase_add_test(tc1_1, my_inverse_matrix_6);
  tcase_add_test(tc1_1, my_inverse_matrix_7);
  tcase_add_test(tc1_1, my_inverse_matrix_8);

  srunner_set_log(sr, "./test/test.log");
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
