/* CodeAlpha Task 2: Matrix Addition, Multiplication and Transpose */
#include <stdio.h>
#define MAX 10

void readMatrix(int a[MAX][MAX], int rows, int cols, const char *name) {
    int i, j;
    printf("Enter elements of %s (%d x %d):\n", name, rows, cols);
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);
}

void displayMatrix(int a[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) printf("%5d", a[i][j]);
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int r, int c) {
    int result[MAX][MAX], i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) result[i][j] = a[i][j] + b[i][j];
    printf("Addition result:\n");
    displayMatrix(result, r, c);
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int c2) {
    int result[MAX][MAX] = {0}, i, j, k;
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            for (k = 0; k < c1; k++) result[i][j] += a[i][k] * b[k][j];
    printf("Multiplication result:\n");
    displayMatrix(result, r1, c2);
}

void transposeMatrix(int a[MAX][MAX], int r, int c) {
    int result[MAX][MAX], i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) result[j][i] = a[i][j];
    printf("Transpose:\n");
    displayMatrix(result, c, r);
}

int main(void) {
    int a[MAX][MAX], b[MAX][MAX], r1, c1, r2, c2, choice;
    printf("===== MATRIX OPERATIONS =====\n");
    printf("1. Addition\n2. Multiplication\n3. Transpose of a matrix\nChoose: ");
    if (scanf("%d", &choice) != 1) return 1;

    if (choice == 1) {
        printf("Enter rows and columns (1-10): ");
        if (scanf("%d %d", &r1, &c1) != 2 || r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
            printf("Invalid dimensions.\n"); return 1;
        }
        readMatrix(a, r1, c1, "Matrix A");
        readMatrix(b, r1, c1, "Matrix B");
        addMatrices(a, b, r1, c1);
    } else if (choice == 2) {
        printf("Enter rows and columns of A (1-10): ");
        if (scanf("%d %d", &r1, &c1) != 2 || r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
            printf("Invalid dimensions.\n"); return 1;
        }
        printf("Enter rows and columns of B (1-10): ");
        if (scanf("%d %d", &r2, &c2) != 2 || r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX || c1 != r2) {
            printf("Invalid dimensions: columns of A must equal rows of B.\n"); return 1;
        }
        readMatrix(a, r1, c1, "Matrix A");
        readMatrix(b, r2, c2, "Matrix B");
        multiplyMatrices(a, b, r1, c1, c2);
    } else if (choice == 3) {
        printf("Enter rows and columns (1-10): ");
        if (scanf("%d %d", &r1, &c1) != 2 || r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
            printf("Invalid dimensions.\n"); return 1;
        }
        readMatrix(a, r1, c1, "Matrix");
        transposeMatrix(a, r1, c1);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
