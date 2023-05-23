#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main()
{
    int num1 = 0;
    int num2 = 0;
    bool checked = false;
    char c;
    while(true) {
        c = getchar();
        if (isnumber(c) && checked == false) {
            num1++;
        }
        if (c == '/') {
            checked = true;
        }
        if (isnumber(c) && checked == true) {
            num2++;
        }
        if (c == EOF | isspace(c)) {
            break;
        }
    }
    int res = num1 / num2;
    for (int i = 0;i < res;i++) {
        printf("1");
    }
    return 0;
}
