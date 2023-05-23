#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
int max (int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int main(int argc, const char * argv[]) {
    int counter_chlenov_first;
    int counter_chlenov_second;
    printf("Введите кол-во членов первого многочлена\n");
    scanf("%d", &counter_chlenov_first);
    printf("Введите кол-во членов второго многочлена\n");
    scanf("%d", &counter_chlenov_second);
    int degrees_one[counter_chlenov_first];
    int degrees_two[counter_chlenov_second];
    int coefficient_one[counter_chlenov_first];
    int coefficient_two[counter_chlenov_second];
    printf("Введите степени каждого члена 1-ого многочлена\n");
    for (int i = 0;i < counter_chlenov_first;i++) {
        scanf("%d", &degrees_one[i]);
    }
    printf("Введите степени каждого члена 2-ого многочлена\n");
    for (int i = 0;i < counter_chlenov_second;i++) {
        scanf("%d", &degrees_two[i]);
    }
    printf("Введите коэффиценты каждого члена 1-ого многочлена\n");
    for (int i = 0;i < counter_chlenov_first;i++) {
        scanf("%d", &coefficient_one[i]);
    }
    printf("Введите коэффиценты каждого члена 2-ого многочлена\n");
    for (int i = 0;i < counter_chlenov_second;i++) {
        scanf("%d", &coefficient_two[i]);
    }
    int final_coefficient[max(counter_chlenov_first, counter_chlenov_second)];
    int final_degree[max(counter_chlenov_first, counter_chlenov_second)];
    for (int i = 0; i < max(counter_chlenov_first, counter_chlenov_second);i++) {
        if (degrees_one[i] == degrees_two[i]) {
            final_degree[i] = degrees_one[i];
        }
        if (degrees_one[i] > degrees_two[i]) {
            final_degree[i] = degrees_one[i];
            final_degree[i++] = degrees_two[i];
        }
        if (degrees_one[i] < degrees_two[i]) {
            final_degree[i] = degrees_two[i];
            final_degree[i++] = degrees_one[i];
        }
    }
    for (int i = 0; i < max(counter_chlenov_first, counter_chlenov_second);i++) {
        if (degrees_one[i] == degrees_two[i]) {
            final_coefficient[i] = coefficient_one[i] + coefficient_two[i];
        } else {
            final_coefficient[i] = max(coefficient_one[i], coefficient_two[i]);
        }
    }
    printf("Получившиеся члены многочлена путем сложения двух:\n");
    for (int i = 0;i < fmax(counter_chlenov_first, counter_chlenov_second);i++) {
        printf("| x | степень: %d | коэффицент: %d |\n", final_degree[i], final_coefficient[i]);
    }
}
