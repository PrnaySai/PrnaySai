#include <stdio.h>
int i,j;
void rotateMatrix(int n, int mat[n][n]) {
    for (i = 0; i < n / 2; i++) {
        for (j = i; j < n - i - 1; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[n - j - 1][i];
            mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
            mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
            mat[j][n - i - 1] = temp;
        }
    }
}

void printMatrix(int n, int mat[n][n]) {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; // Change this to the desired size of the matrix
    int mat[4][4] = {{6,3,7,10},
                    {11,3,54,7},
                    {2,34,51,9},
                    {13,43,67,1}};

    printf("Original Matrix:\n");
    printMatrix(n, mat);

    rotateMatrix(n, mat);

    printf("\nMatrix after rotation:\n");
    printMatrix(n, mat);

    return 0;
}
