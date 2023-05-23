#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

int main (int argc, const char * argv[])
{
    double a, b, a1, b1;
    printf("Введите координаты 1-ого отрезка\n");
    scanf("%lf%lf", &a, &b);
    printf("Введите координаты 2-ого отрезка\n");
    scanf("%lf%lf", &a1, &b1);
    if (b < a1) {
        printf("No");
        return 0;
    }
    if (b1 < a) {
        printf("No");
        return 0;
    }
    printf("Yes");
    return 0;
}

