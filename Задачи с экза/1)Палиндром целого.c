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
    int number;
    printf("Введите число\n");
    scanf("%d", &number);
    int number_check = number;
    int number_reversed = 0;
    while (number_check) {
        int last_num = 0;
        last_num = number_check % 10;
        number_reversed = number_reversed * 10 + last_num;
        number_check /= 10;
    }
    if (number_reversed == number) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
