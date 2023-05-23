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
    long double number;
    scanf("%Lf", &number);
    int del=1;
    while((long int)number != ceil(number)){
        number *= 10;
        del *= 10;
    }
    printf("%d / %d", (int) number, del);
}

