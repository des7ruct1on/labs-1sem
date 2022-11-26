/*
    Ляпин Иван Алексеевич
    М8О-104Б-22
    Вариант №27
*/

#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

long long even (long long a) // если длина введенного числа четная
{
    unsigned long long new = 0; //значение функции
    long long k = 1; // создаем счетчик для перехода к следующей парец цифр
    
    int first, second, third; //first - последняя цифра числа, second - предпоследняя,
    //third - их разность под модулем, k - коэффициент для записи выходного числа new
    if (a > INT_MAX) { // проверка на переполненеи int
        printf("Переполнение!Введите новое число");
        return 0;
    }
    while (a > 0) {
        first = a % 10; // берем последний разряд числа и запоминаем
        a /= 10; //  "вычеркиваем" его 
        second = a % 10; // берем следующий разряд и запоминаем
        a /= 10; // "вычеркиваем" его 
        third = abs(first - second); // вычисляем модуль разности 
        /* восстанавливаем исходное число по паре + значение их разности */
        new += first * k + second * 10 * k + third * 100 * k; 
        k *= 1000; //увеличиваем k, так как мы предыдущие разряды уже записаны
    }
    return new;
}

long long odd (long long b) // если длина введенного числа нечетная
{   // действия аналогичны функции even()
    unsigned long long new = 0;
    
    long long k = 1;
    
    int first, second, third, last;
    
    if (b > INT_MAX) {
        printf("Переполнение!Введите новое число");
        return 0;
    }
    while (b >= 10) {
        first = b % 10;
        b /= 10;
        second = b % 10;
        b /= 10;
        third = abs( first - second);
        new += first * k + second * 10 * k + third * 100 * k;
        k *= 1000;
    }
    last = b % 10;
    new += last * k; // добавляем последнюю цифру к new, так как у этой цифры нет пары для сравнения
    return new;
}

int main()
{
    long long num_keyboard, num_k_check; // num_keyboard - число, введенное с клавиатуры, num_k_check - для проверки длины числа
    int length = 0; // длина числа
    long long flag = 1; // длина вводимого числа, flag - для определения знака
  
    printf("Введите число или ^D для завершения программы: \n");
    while (scanf("%lld", &num_keyboard) != EOF) {
        if (num_keyboard < 0) { // проверка на знак
            num_keyboard = abs( num_keyboard );
            flag = -1;
        }
        num_k_check = num_keyboard;
        while ( num_k_check != 0 ) { // проверяем на четность и нечетность длину нашего числа
            length ++ ;
            num_k_check /= 10;
        }
        if ( length % 2 == 0) { //если четная длина
            
            printf("%lld\n", even(num_keyboard) * flag); // функция обработки четного числа
        } else { //если нечетная длина
            printf("%lld\n", odd(num_keyboard) * flag); // функция обработки нечетного числа
        }
        length = 0; // возвращаем наши значения для дальнейших операций
        flag = 1;
        printf("Введите число или ^D для завершения программы: \n");
    }
}
