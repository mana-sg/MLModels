#include<stdio.h>
#include<math.h>
#include"matrix_operations.h"

void mat_mul(int rowsA, int colsA, double A[rowsA][colsA], int rowsB, int colsB, double B[rowsB][colsB],double result[rowsA][colsB]) {
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

void mat_trans(int rows, int cols, double matrix[rows][cols], double result[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void mat_swapRows(int N, double A[N][N], int row1, int row2) {
    for (int j = 0; j < N; j++) {
        double temp = A[row1][j];
        A[row1][j] = A[row2][j];
        A[row2][j] = temp;
    }
}

void mat_scaleRow(int N, double A[N][N], int row, double factor) {
    for (int j = 0; j < N; j++) {
        A[row][j] *= factor;
    }
}

void mat_AddScaledRow(int N, double A[N][N], int sourceRow, int targetRow, double factor) {
    for (int j = 0; j < N; j++) {
        A[targetRow][j] += factor * A[sourceRow][j];
    }
}

void mat_invert(int N, double A[N][N], double inverse[N][N]) {
    // Initialize the inverse matrix as the identity matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inverse[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Perform Gaussian elimination with partial pivoting
    for (int i = 0; i < N; i++) {
        // Find the pivot row (maximum absolute value in the column)
        int pivotRow = i;
        for (int k = i + 1; k < N; k++) {
            if (fabs(A[k][i]) > fabs(A[pivotRow][i])) {
                pivotRow = k;
            }
        }

        // Swap rows to make the pivot element the largest in the column
        mat_swapRows(N, A, i, pivotRow);
        mat_swapRows(N, inverse, i, pivotRow);

        // Scale the pivot row to make the pivot element equal to 1
        double pivotElement = A[i][i];
        mat_scaleRow(N, A, i, 1.0 / pivotElement);
        mat_scaleRow(N, inverse, i, 1.0 / pivotElement);

        // Eliminate other rows to make the column below the pivot element zero
        for (int k = 0; k < N; k++) {
            if (k != i) {
                double factor = -A[k][i];
                mat_AddScaledRow(N, A, i, k, factor);
                mat_AddScaledRow(N, inverse, i, k, factor);
            }
        }
    }
}

void printMatrix(int N, double A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f\t", A[i][j]);
        }
        printf("\n");
    }
}

