#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
int divs (int a)
{
    int counter_divs = 0;
    int b = pow(a, 0.5);
    for (int i = 1;i < b + 1;i++) {
        if (a % i == 0) {
            counter_divs++;
            if (i != a / i) {
                counter_divs++;
            }
        }
    }
    return counter_divs;
}
int main(int argc, const char * argv[]) {
    for (int i = 0;i < 1000;i++) {
        if(divs(i) == 2) {
            printf("%d\t", i);
        }
    }
    
    return 0;
}
