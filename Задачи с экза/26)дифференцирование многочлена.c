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
    int num_of_chlenov;
    printf("Введите количество членов\n");
    scanf("%d", &num_of_chlenov);
    int degrees[num_of_chlenov];
    printf("Введите степени многочлена, начиная со старшей\n");
    for (int i = 0;i < num_of_chlenov;i++) {
        scanf("%d", &degrees[i]);
    }
    int coefficents[num_of_chlenov];
    printf("Введите коэффиценты многочлена, начиная со старшего\n");
    for (int i = 0;i < num_of_chlenov;i++) {
        scanf("%d", &coefficents[i]);
    }
    for (int i = 0;i < num_of_chlenov;i++) {
        printf("| x | степень: %3d | коэффицент: %3d |\n", (degrees[i] - 1), (coefficents[i] * degrees[i]));
    }
}

