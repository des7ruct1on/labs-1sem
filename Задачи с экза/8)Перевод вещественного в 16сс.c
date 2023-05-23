#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>



int main (int argc, const char * argv[])
{
    long double n;
    int t;
    scanf("%Lf %d", &n, &t);
    printf("%x.", (unsigned int) n);

    for (int i = 0; i < t; i++) {
        n -= trunc(n);
        n *= 16;
        if (trunc(n) == 15) {
            printf("F");
        } else if (trunc(n) == 14) {
            printf("E");
        } else if (trunc(n) == 13) {
            printf("D");
        } else if (trunc(n) == 12) {
            printf("C");
        } else if (trunc(n) == 11) {
            printf("B");
        } else if (trunc(n) == 10) {
            printf("A");
        } else {
            printf("%d", (int) trunc(n));
        }
    }
    return 0;
}


