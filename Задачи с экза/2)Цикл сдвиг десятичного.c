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
    int number, n;
    int number_check;
    int len_number = 0;
    printf("Введите число\n");
    scanf("%d", &number);
    printf("Введите значение сдвига\n");
    scanf("%d", &n);

    number_check = number;
    while (number_check) {
        number_check /= 10;
        len_number++;
    }
    number_check = 0;
    while (n) {
        n --;
        number_check = number % 10;
        number += number_check * pow(10, len_number);
        number = number / 10;
    }

    printf("%d", number);
    return 0;
}
