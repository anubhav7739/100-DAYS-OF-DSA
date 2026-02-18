/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/

#include <stdio.h>
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = *matrixColSize;

    *returnSize = cols;

    *returnColumnSizes = (int*)malloc(cols * sizeof(int));

    int** result = (int**)malloc(cols * sizeof(int*));

    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
        (*returnColumnSizes)[i] = rows;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

void printMatrix(int** matrix, int rows, int* colSizes) {
    printf("[");
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d%s", matrix[i][j], (j == colSizes[i] - 1) ? "" : ",");
        }
        printf("]%s", (i == rows - 1) ? "" : ",");
    }
    printf("]\n");
}

int main() {
    int rows = 2;
    int cols = 3;

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) matrix[i] = (int*)malloc(cols * sizeof(int));

    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;

    int returnSize;
    int* returnColumnSizes;

    int** result = transpose(matrix, rows, &cols, &returnSize, &returnColumnSizes);

    printf("Input: [[1,2,3],[4,5,6]]\n");
    printf("Output: ");
    printMatrix(result, returnSize, returnColumnSizes);

    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);

    for (int i = 0; i < returnSize; i++) free(result[i]);
    free(result);
    free(returnColumnSizes);

    return 0;
}