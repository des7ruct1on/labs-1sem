#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#define MAX 200


int main (int argc, const char * argv[])
{
    // График sin(x)
        
    long double x = 0.0;
        
    while (x < 100) {
        if (roundl(sinl(x) * 10) >= 0) {
            printf("          ");
            for (long double i = 0; i < roundl(sinl(x) * 10); i++) {
                printf(" ");
            }
        } else {
            for (long double i = -10; i < roundl(sinl(x) * 10); i++) {
                printf(" ");
            }
                
        }
        printf("@\n");
        x += 0.2;
            
    }
    return 0;
}


