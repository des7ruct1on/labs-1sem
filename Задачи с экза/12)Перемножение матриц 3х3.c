#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, const char * argv[]) {
    int matrix1[3][3];
    int matrix2[3][3];
    int matrix_multiply[3][3];
    printf("Введите эл-ты 1-ой матрицы\n");
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Введите эл-ты 2-ой матрицы\n");
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            matrix_multiply[i][j] = 0;
            for (int k = 0;k < 3;k++) {
                matrix_multiply[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    int counter_numbers = 0;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            printf("%d\t", matrix_multiply[i][j]);
            counter_numbers++;
            if (counter_numbers == 3) {
                printf("\n");
                counter_numbers = 0;
            }
            
        }
    }
    
}

