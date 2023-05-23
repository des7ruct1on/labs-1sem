#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

int main (int argc, const char * argv[])
{
    int num_of_chlens;
    printf("Введите количество членов\n");
    scanf("%d", &num_of_chlens);
    int degrees[num_of_chlens];
    int coefficents[num_of_chlens];
    printf("Введите степени каждого члена\n");
    for (int i = 0;i < num_of_chlens;i++) {
        scanf("%d", &degrees[i]);
    }
    printf("Введите коэффиценты каждого члена\n");
    for (int i = 0;i < num_of_chlens;i++) {
        scanf("%d", &coefficents[i]);
    }
    for (int x = 0;x < 100;x++) {
        long long result = 0;
        for (int i = 0;i < num_of_chlens;i++) {
            result += coefficents[i] * pow(x, degrees[i]);
        }
        printf("| x = %d | result = %lld |\n", x, result);
    }
    return 0;
}

