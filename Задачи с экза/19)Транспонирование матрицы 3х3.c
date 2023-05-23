#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, const char * argv[]) {
    int matrix[3][3];
    int matrix_trans[3][3];
    printf("Введите эл-ты матрицы\n");
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j <3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j <3; j++) {
            matrix_trans[j][i] = matrix[i][j];
        }
    }
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j <3; j++) {
            printf("%d\t", matrix_trans[i][j]);
        }
    }
}

