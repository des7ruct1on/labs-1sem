/*
    Ляпин Иван Алексеевич
    М8О-104Б-22
    КП 3
    Вариант 8
*/

#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

double FEps (void) // функция для вычисления машинного эпсилона
{
    double eps = 1.0;
    while (eps / 2.0 + 1.0 > 1.0) {
        eps /= 2.0;
    }
    return eps;
}
double Function (double x) // функция, вычисляемая обычным методом
{
    return (1 / (2 * x - 5)); // выводим значение функции
}


int main (int argc, const char * argv[])
{
    double a = 0.0; //начало отрезка
    double b = 2.0; //конец отрезка
    int k, n; // k - коэффицент точности, n - количество раделенных отрезков
    double eps = FEps(); // значение машинного эпсилона
    int countIter = 0; // количество итераций
    double FTaylor; // функция Тейлора
    double sum = 0.0; // сумма ряда Тейлора
    printf("Введите коэффицент точности и количество разбиений [a, b]\n");
    scanf("%d %d", &k, &n); // считываем значение коэффицента точности и количество разделений
    printf("Машинное Эписилон = %0.16lf\n", eps); // выводим значение eps с точностью до 16 знака после точки
    printf("|------------------------------------------------|\n"); // чертим структуру таблицы
    printf("|  x   |    Taylor     |   1 / (2x - 5)   | Step |\n");
    printf("|------|---------------|------------------|------|\n");
    for (double x = a;x <= b;x += (b - a) / n) { // запускаем цикл прохождения по отрезку с шагом, равному длине разделенного отрезка
        while (countIter < 100 || (fabs(Function(x)) - fabs(sum) < eps * k)) { // цикл до 100 итераций, либо пока разница между значениями функции и функции тейлора не будет меньше eps * k
            countIter += 1; // увеличиваем счетчик итерацию на единицу
            FTaylor = ((pow(2, countIter - 1) * (pow(x, countIter - 1))) / pow(5, countIter)); // вычисляем член ряда
            sum -= FTaylor; // считаем сумму ряда
            if (fabs(Function(x)) - fabs(sum) < eps * k) { // если
                break;
            }
        }
        printf("| %0.2lf | %0.10lf | %0.10lf    | %3d  |\n", x, sum, Function(x), countIter);
        countIter = 0;
        sum = 0;
    }
    
    
    printf("|------------------------------------------------|\n"); // закрываем таблицу
    return 0;
}
        




