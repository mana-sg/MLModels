#ifndef MATRIX_OPERATIONS_h
#define MATRIX_OPERATIONS_h

void mat_mul(int rowsA, int colsA, int A[rowsA][colsA], int rowsB, int colsB, int B[rowsB][colsB],int result[rowsA][colsB]);
void mat_trans(int rows, int cols, int matrix[rows][cols], int result[cols][rows]);

#endif
