#include "../headers/my_matrix.h"

#include "../headers/extra.h"

/// @brief | Создаёт матрицу размером M x N |
/// @param rows -  кол-во строк int
/// @param columns -  кол-во столбцов int
/// @param result -  указатель на matrix_t
/// @return
/// 0 - OK;
/// 1 - некорректная матрица;
/// 2 - ошибка вычисления
int my_create_matrix(int rows, int columns, matrix_t *result) {
  int output = OK;
  if (result == NULL || rows <= 0 || columns <= 0) {
    output = INPUT_ERROR;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      output = CALC_ERROR;
    } else {
      int memmory_error = FALSE;
      int num_row = 0;
      for (; num_row < rows; num_row++) {
        result->matrix[num_row] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[num_row] == NULL) {
          memmory_error = TRUE;
          break;
        }
      }
      if (memmory_error) {
        output = CALC_ERROR;
        for (int i = 0; i < num_row; i++) {
          free(result->matrix[i]);
        }
        free(result->matrix);
        result->rows = 0;
        result->columns = 0;
        result->matrix = NULL;
      } else {
        result->rows = rows;
        result->columns = columns;
      }
    }
  }
  return output;
}

/// @brief | Удаление указателей на матрицу |
/// @param A -  указатель на matrix_t
void my_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (check_matrix(A) == SUCCESS) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
      }
      free(A->matrix);
      A->rows = 0;
      A->columns = 0;
      A->matrix = NULL;
    }
  }
}

/// @brief | Сравнивает две матрицы |
/// @param A -  указатель на matrix_t
/// @param B -  указатель на matrix_t
/// @return
/// 0 - FAILURE;
/// 1 - SUCCESS
int my_eq_matrix(matrix_t *A, matrix_t *B) {
  int output = SUCCESS;
  if (check_matrix(A) == FAILURE || check_matrix(B) == FAILURE) {
    output = FAILURE;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    output = FAILURE;
  } else {
    for (int i = 0; i < A->rows && output == SUCCESS; i++) {
      for (int j = 0; j < A->columns && output == SUCCESS; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
          output = FAILURE;
        }
      }
    }
  }
  return output;
}

/// @brief | Складывает две матрицы |
/// @param A -  указатель на matrix_t
/// @param B -  указатель на matrix_t
/// @param result -  указатель на matrix_t
/// @return
/// 0 - OK;
/// 1 - некорректная матрица;
/// 2 - ошибка вычисления
int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int output = OK;
  if (check_matrix(A) == FAILURE || check_matrix(B) == FAILURE ||
      result == NULL) {
    output = INPUT_ERROR;
  } else if (!(A->rows == B->rows && A->columns == B->columns)) {
    output = CALC_ERROR;
  } else {
    output = my_create_matrix(A->rows, A->columns, result);
    if (output == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return output;
}

/// @brief | Вычитает две матрицы |
/// @param A -  указатель на matrix_t
/// @param B -  указатель на matrix_t
/// @param result -  указатель на matrix_t
/// @return
/// 0 - OK;
/// 1 - некорректная матрица;
/// 2 - ошибка вычисления
int my_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int output = OK;
  if (check_matrix(A) == FAILURE || check_matrix(B) == FAILURE ||
      result == NULL) {
    output = INPUT_ERROR;
  } else if (!(A->rows == B->rows && A->columns == B->columns)) {
    output = CALC_ERROR;
  } else {
    output = my_create_matrix(A->rows, A->columns, result);
    if (output == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return output;
}

/// @brief | Умножает матрицу на число |
/// @param A -  указатель на matrix_t
/// @param number -  число double
/// @param result -  указатель на matrix_t
/// @return
/// 0 - OK;
/// 1 - некорректная матрица;
/// 2 - ошибка вычисления
int my_mult_number(matrix_t *A, double number, matrix_t *result) {
  int output = OK;
  if (check_matrix(A) == FAILURE || result == NULL) {
    output = INPUT_ERROR;
  } else {
    output = my_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && output == OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }
  return output;
}

/// @brief | Умножает матрицу А на матрицу В |
/// @param A -  указатель на matrix_t
/// @param B -  указатель на matrix_t
/// @param result -  указатель на matrix_t
/// @return
/// 0 - OK;
/// 1 - некорректная матрица;
/// 2 - ошибка вычисления
int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int output = OK;
  if (check_matrix(A) == FAILURE || check_matrix(B) == FAILURE ||
      result == NULL) {
    output = INPUT_ERROR;
  } else if (A->columns != B->rows) {
    output = CALC_ERROR;
  } else {
    output = my_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows && output == OK; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0.0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return output;
}

/// @brief | Транспонирует матрицу А |
/// @param A -  указатель на matrix_t
/// @param result -  указатель на matrix_t
/// @return
/// 0 - OK;
/// 1 - некорректная матрица;
/// 2 - ошибка вычисления
int my_transpose(matrix_t *A, matrix_t *result) {
  int output = OK;
  if (check_matrix(A) == FAILURE || result == NULL) {
    output = INPUT_ERROR;
  } else {
    output = my_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows && output == OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return output;
}

/// @brief | Вычисляет определитель матрицы А |
/// @param A -  указатель на matrix_t
/// @param result -  указатель на double
/// @return
/// 0 - OK;
/// 1 - некорректная матрица;
/// 2 - ошибка вычисления
int my_determinant(matrix_t *A, double *result) {
  int output = OK;
  if (result != NULL) *result = 0.0;
  if (check_matrix(A) == FAILURE || result == NULL) {
    output = INPUT_ERROR;
  } else if (A->rows != A->columns) {
    output = CALC_ERROR;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result = (A->matrix[0][0] * A->matrix[1][1]) -
                (A->matrix[0][1] * A->matrix[1][0]);
    } else {
      double tmp = 0.0;
      for (int j = 0; j < A->columns && output == OK; j++) {
        matrix_t minor = {0};
        output = get_minor(A, 0, j, &minor);
        if (output == OK) {
          output = my_determinant(&minor, &tmp);
          if (output == OK) {
            *result += A->matrix[0][j] * pow(-1.0, j) * tmp;
          }
          my_remove_matrix(&minor);
        }
      }
    }
  }
  return output;
}

/// @brief | Вычисление матрицы алгебраических дополнений матрицы А |
/// @param A -  указатель на matrix_t
/// @param result -  указатель на matrix_t
/// @return
/// 0 - OK;
/// 1 - некорректная матрица;
/// 2 - ошибка вычисления
int my_calc_complements(matrix_t *A, matrix_t *result) {
  int output = OK;
  if (check_matrix(A) == FAILURE || result == NULL) {
    output = INPUT_ERROR;
  } else if (A->rows != A->columns) {
    output = CALC_ERROR;
  } else {
    output = my_create_matrix(A->rows, A->columns, result);
    if (output == OK) {
      if (A->rows == 1) {
        result->matrix[0][0] = 1;
      } else {
        double determinant = 0.0;
        matrix_t minor = {0};
        for (int i = 0; i < A->rows && output == OK; i++) {
          for (int j = 0; j < A->columns && output == OK; j++) {
            output = get_minor(A, i, j, &minor);
            if (output == OK) {
              output = my_determinant(&minor, &determinant);
              if (output == OK) {
                result->matrix[i][j] = pow(-1.0, i + j) * determinant;
              }
              my_remove_matrix(&minor);
            }
          }
        }
      }
    }
  }
  return output;
}

/// @brief | Вычисление обратной матрицы для матрицы А |
/// @param A -  указатель на matrix_t
/// @param result -  указатель на matrix_t
/// @return
/// 0 - OK;
/// 1 - некорректная матрица;
/// 2 - ошибка вычисления
int my_inverse_matrix(matrix_t *A, matrix_t *result) {
  int output = OK;
  if (check_matrix(A) == FAILURE || result == NULL) {
    output = INPUT_ERROR;
  } else if (A->rows != A->columns) {
    output = CALC_ERROR;
  } else {
    double deter = 0.0;
    output = my_determinant(A, &deter);
    if (deter == 0.0 || output != OK) {
      output = CALC_ERROR;
    } else {
      matrix_t complements = {0};
      output = my_calc_complements(A, &complements);
      if (output == OK) {
        matrix_t trans = {0};
        output = my_transpose(&complements, &trans);
        if (output == OK) {
          output = my_mult_number(&trans, 1.0 / deter, result);
          my_remove_matrix(&trans);
        }
        my_remove_matrix(&complements);
      }
    }
  }
  return output;
}
