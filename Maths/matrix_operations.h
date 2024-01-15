#ifndef MATRIX_OPERATIONS_h
#define MATRIX_OPERATIONS_h

void mat_mul(int rowsA, int colsA, double A[rowsA][colsA], int rowsB, int colsB, double B[rowsB][colsB],double result[rowsA][colsB]);
void mat_trans(int rows, int cols, double matrix[rows][cols], double result[cols][rows]);
void mat_invert(int N, double A[N][N], double inverse[N][N]);
void mat_AddScaledRow(int N, double A[N][N], int sourceRow, int targetRow, double factor);
void mat_scaleRow(int N, double A[N][N], int row, double factor);
void mat_swapRows(int N, double A[N][N], int row1, int row2);
void printMatrix(int N, double A[N][N]);

#endif
