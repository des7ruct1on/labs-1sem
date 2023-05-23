#include <stdio.h>

void SpellTriade(int triade, int i) {
    int decs = triade % 100;
    int hundreds = (triade / 100) % 10;
    switch (hundreds) {
        case 1:
            printf("сто ");
            break;
        case 2:
            printf("двести ");
            break;
        case 3:
            printf("триста ");
            break;
        case 4:
            printf("четыреста ");
            break;
        case 5:
            printf("пятьсот" );
            break;
        case 6:
            printf("шестьсот ");
            break;
        case 7:
            printf("семсот ");
            break;
        case 8:
            printf("восемсот ");
            break;
        case 9:
            printf("девятсот ");
            break;
    }
    if (decs < 20 && decs >= 10) {
        switch (decs) {
            case 10:
                printf("десять ");
                break;
            case 11:
                printf("одиннадцать ");
                break;
            case 12:
                printf("двенадцать ");
                break;
            case 13:
                printf("тринадцать ");
                break;
            case 14:
                printf("четырнадцать ");
                break;
            case 15:
                printf("пятнадцать ");
                break;
            case 16:
                printf("шестнадцать ");
                break;
            case 17:
                printf("семнадцать ");
                break;
            case 18:
                printf("восемнадцать ");
                break;
            case 19:
                printf("девятнадцать ");
                break;
        }
    } else {
        switch (decs / 10) {
            case 2:
                printf("двадцать ");
                break;
            case 3:
                printf("тридцать ");
                break;
            case 4:
                printf("сорок ");
                break;
            case 5:
                printf("пятьдесят ");
                break;
            case 6:
                printf("шестьдесят ");
                break;
            case 7:
                printf("семьдесят ");
                break;
            case 8:
                printf("восемьдесят ");
                break;
            case 9:
                printf("девяносто ");
                break;
        }

        switch (decs % 10) {
            case 1:
                if (i == 2) {
                    if (decs / 10 != 0) {
                        printf("одна ");
                    }
                } else {
                    printf("один ");
                }
                break;
            case 2:
                if (i == 2) {
                    printf("две ");
                } else {
                    printf("два ");
                }
                break;
            case 3:
                printf("три ");
                break;
            case 4:
                printf("четыре ");
                break;
            case 5:
                printf("пять ");
                break;
            case 6:
                printf("шесть ");
                break;
            case 7:
                printf("семь ");
                break;
            case 8:
                printf("восемь  ");
                break;
            case 9:
                printf("девять ");
                break;
        }
    }
    
    if (decs / 10 == 1 || decs % 10 > 4 || (triade != 0 && triade % 10 == 0)) {
        if (i == 2) {
            printf("тысяч ");
        } else if (i == 3) {
            printf("миллионов ");
        } else if (i == 4) {
            printf("миллиардов ");
        } else if (i == 5) {
            printf("триллионов ");
        } 
    } else {
        switch (decs % 10) {
            case 1:
               if (i == 2) {
                    printf("тысяча ");
                } else if (i == 3) {
                    printf("миллион ");
                } else if (i == 4) {
                    printf("миллиард ");
                } else if (i == 5) {
                    printf("триллион ");
                }
                break;
            case 2:
            case 3:
            case 4:
                if (i == 2) {
                    printf("тысячи ");
                } else if (i == 3) {
                    printf("миллиона ");
                } else if (i == 4) {
                    printf("миллиарда ");
                } else if (i == 5) {
                    printf("триллиона ");
                }
                break;
        }
    }

}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("ноль");
    } else {
        int k = 1;
        int l = 0;
        int a = n;
        while (a) {
            a /= 10;
            l += 1;
        }
        l = l / 3 + (l % 3 == 0 ? 0 : 1);
        for (int i = 0; i < l; i++) {
            k *= 1000;
        }
        

        for (int i = l; i > 0; i--) {
            int triade = n / (k / 1000);
            if (triade != 0) {
                SpellTriade(triade, i);
            }
            k /= 1000;
            n %= k;
        }
        
    }

    
}