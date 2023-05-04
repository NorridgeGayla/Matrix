#include "../headers/extra.h"

/// @brief | Проверяет указатель на матрицу на корректность |
/// @param T -  указатель на matrix_t
/// @return
/// 0 - FAILURE;
/// 1 - SUCCESS
int check_matrix(matrix_t *T) {
  int output = SUCCESS;
  if (T == NULL) {
    output = FAILURE;
  } else if (T->matrix == NULL || T->rows <= 0 || T->columns <= 0) {
    output = FAILURE;
  }
  return output;
}

/// @brief | Получение минора из исходной матрицы А, путем удаления строки и
/// столбца |
/// @param T -  указатель на matrix_t
/// @param delete_row -  число int
/// @param delete_column -  число int
/// @param result -  указатель на matrix_t
/// @return
/// 0 - OK;
/// 1 - некорректная матрица;
/// 2 - ошибка вычисления
int get_minor(matrix_t *T, int delete_row, int delete_column,
              matrix_t *result) {
  int output = OK;
  if (check_matrix(T) == FAILURE || result == NULL) {
    output = INPUT_ERROR;
  } else if (delete_row < 0 || delete_row >= T->rows || delete_column < 0 ||
             delete_column >= T->columns || (T->rows == 1 && T->columns == 1)) {
    output = INPUT_ERROR;
  } else {
    output = my_create_matrix(T->rows - 1, T->columns - 1, result);
    if (output == OK) {
      for (int i = 0, num_row = 0; i < T->rows; i++) {
        if (i != delete_row) {
          for (int j = 0, num_column = 0; j < T->columns; j++) {
            if (j == delete_column) {
              continue;
            }
            result->matrix[num_row][num_column] = T->matrix[i][j];
            num_column++;
          }
          num_row++;
        }
      }
    }
  }
  return output;
}

// /// @brief | Ввод значений матрицы через консоль |
// /// @param T -  указатель на matrix_t
// void input_matrix(matrix_t *T) {
//   if (T != NULL && check_matrix(T) == SUCCESS) {
//     for (int i = 0; i < T->rows; i++) {
//       for (int j = 0; j < T->columns; j++) {
//         scanf("%lf", &T->matrix[i][j]);
//       }
//     }
//   }
// }

// /// @brief | Печать матрицы |
// /// @param T -  указатель на matrix_t
// void print_matrix(matrix_t *T) {
//   if (T != NULL && check_matrix(T) == SUCCESS) {
//     for (int i = 0; i < T->rows; i++) {
//       for (int j = 0; j < T->columns; j++) {
//         printf("%.8lf ", T->matrix[i][j]);
//       }
//       printf("\n");
//     }
//   }
// }
