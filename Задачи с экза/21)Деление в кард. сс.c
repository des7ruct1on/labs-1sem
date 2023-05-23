#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>



int main (int argc, const char * argv[])
{
    char num1[100];
    char num2[100];
    scanf("%s %s", num1, num2);
    char num1_minus = strlen(num1) - 1;
    char num2_minus = strlen(num2) - 1;
    while (num1_minus) {
        num1_minus -= num2_minus;
        printf("1");
    }
    printf("1");
    return 0;
}


