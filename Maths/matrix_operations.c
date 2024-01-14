#include<stdio.h>
#include"matrix_operations.h"

void mat_mul(int rowsA, int colsA, int A[rowsA][colsA], int rowsB, int colsB, int B[rowsB][colsB],int result[rowsA][colsB]) {
    if (colsA != rowsB) {
        printf("Error: Incompatible matrix sizes for multiplication.\n");
        return;
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mat_trans(int rows, int cols, int matrix[rows][cols], int result[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
