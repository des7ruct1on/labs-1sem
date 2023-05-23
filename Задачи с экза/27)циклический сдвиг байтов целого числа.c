#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>



int main (int argc, const char * argv[])
{
    int a, n;
    scanf("%d", &a);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        a = (0xFF000000 & a) >> 24 | a << 8;
    }
    printf("%d", a);
    return 0;
}


