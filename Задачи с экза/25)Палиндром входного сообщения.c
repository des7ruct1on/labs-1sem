#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

int main (int argc, const char * argv[])
{
    int len;
    printf("Введите длину слова\n");
    scanf("%d", &len);
    char word[len];
    printf("Введите слово\n");
    scanf("%s", word);
    for (int i = 0;i < len /2;i++) {
        if (word[i] != word[len - 1 - i]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

