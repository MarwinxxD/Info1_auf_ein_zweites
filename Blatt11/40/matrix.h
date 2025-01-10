#ifndef MATRIX_H
#define MATRIX_H

#define MATRIX_DIM_ERR 1
#define MATRIX_MEM_ERR -1
#define MATRIX_VALID 0

int matrix_add(int rowsA, int colsA, int **A, int rowsB, int colsB, int **B, int **C);
int matrix_transpose(int rows, int cols, int **A, int **T);
int matrix_multiply(int rowsA, int colsA, int **A, int rowsB, int colsB, int **B, int **C);
int matrix_randomize(int rows, int cols, int **matrix);
int matrix_print(int rows, int cols, int **matrix);
int **matrix_allocate(int rows, int cols); 
void matrix_free(int **matrix, int rows);

#endif
