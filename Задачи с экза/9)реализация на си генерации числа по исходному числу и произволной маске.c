#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

int main (int argc, const char * argv[])
{
    printf("Введите сначало число, по которому вы хотите сгенерировать новое (в 10 сс), после маску, так же в 10 сс: \n");
    int n, m, ln = 0, i = 0;
    scanf("%d %d", &n, &m);
        
    int m1 = m;
    while (m1 > 0) {
        if (m1 % 2) ln ++;
        m1/=2;
    }
    int ms[ln];
    while (m > 0) {
        if (m % 2) {
            ms[ln - 1 - i] = n % 2;
            i++;
        }
        m/=2;
        n/=2;
    }
    for (int i = 0; i < ln; i++) {
        printf("%d", ms[i]);
    }
    return 0;
}

