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
    int n, num;
    scanf("%d", &num);
    scanf("%d", &n);
    printf("%d", (num >> (8 * n)) & 255);
    return 0;
}
