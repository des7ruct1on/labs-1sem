/*
    Ляпин Иван Алексеевич
    М8О-104Б-22
    КП 4
    Вариант 19, 20
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
    while (eps + 1.0 > 1.0) {
        eps /= 2.0;
    }
    return eps;
}
double Func1 (double x) // первая функция
{
    return x - 1 / (3 + sin(3.6*x)) ;
}
double Func2 (double x) // вторая функция
{
    return ((pow(x, 2) * 0.1) - (x * log(x)));
}
double Func1_diff (double x) // производная первой функции
{
    return 1 + (18 * cos(3.6 * x) / 5 * pow(3 + sin(3.6 * x), 2));
}
double Func2_diff (double x) // производная второй функции
{
    return (0.2 * x - log(x) - 1);
}
double Func1_diff2 (double x) // производная первой функции
{
    return (-3240 * sin(3.6 * x) - 1944 - 324 * sin(3.6 * x) * pow(cos(3.6 * x), 2)) / (25 * pow(3  + sin(3.6 * x), 4));
}
double Func2_diff2 (double x) // производная второй функции
{
    return 0.2 - (1 / x);
}
double Root_Func1 (double x) // функция 1, вычленная корнем
{
    return 1 / (3 + sin(3.6 * x));
}
double Root_Func2 (double x) // функция 2, вычленная корнем
{
    return (0.1 * pow(x, 2)) / log(x);
}
double Root_Func1_diff(double x) { // производная от функции 1, вычленной корнем
    return (-6 * cos(3.6 * x)) / (5 * pow(sin(3.6 * x), 2));
}
double Root_Func2_diff(double x) { // производная от функции 2, вычленной корнем
    return (2 * x * log(x) - x) / (10 * pow(log(x), 2));
}
double Iterations (double a, double b, double EPS, double f(double), double f_diff(double)) // производим метод итераций
{
    double x; // заведем аргумент x
    int counterIter = 0; // заводим счетчик итераций, чтобы дать верхнюю границу
    x = (a + b) / 2; // присваиваем x значение середины отрезка
    
    if (fabs(f_diff(x)) < 1 && (fabs(f_diff(x / 1.5)) < 1)) { // проверяем на сходимость метода, то есть производная от функции, вычленной корнем должна быть < 1 по модулю
        while (fabs(f(x) - x) > EPS && counterIter < 100) { // заводим цикл, пока абсолютная разница не будет < некторого машинного эпсилона или кол-во итераций = 100
            x = f(x);
            counterIter++;
        }
    } else { // если метод невыполним, то завершаем функцию
        
        return 0;
        
    }
    return x; // выводим значение корня
}
double Newton (double a, double b, double EPS, double f(double), double f_2(double), double f_2_diff (double)) // создаем функцию, вычисл. корень по Ньютону
{
    double x;
    x = (a + b) / 2; // значение середины отрезка
    if (fabs(f(x) * f_2_diff(x)) <= pow(f_2(x), 2)) { // проверка на выполнение метода
        while (fabs(f(x) / f_2(x)) > EPS) { // цикл, пока значение деление не стало меньшим или равным eps
            x -= f(x) / f_2(x); // вычитаем из x
        }
    } else { // выводим 0 , если метод неприменим
        
        return 0;
        
    }
    return x; // выводим корень уравнения
}
double Dikhotomy (double a, double b, double EPS, double f(double))
{
    double x;
    int counter = 0; // заводим счетчик итераций цикла, чтобы определить верхнуюю границу
    if (f(a) * f(b) < 0) { // проверка выполения метода
        while (fabs(a - b) > EPS && counter < 100) { // цикл пока сближение небудет меньшим или равным eps
            x = (a + b) / 2; // придаем аргументы значение середины отрезка в момент итерации
            if (f(a) * f((a + b) / 2) > 0) { // условие выполнения
                a = (a + b) / 2; // проводим сближение
                b = b;
            }
            if (f(b) * f((a + b) / 2) > 0) { // условие выполнения
                b = (a + b) / 2; // проводим сближение
                a = a;
            }
            counter++;
        }
    } else { // если метод невыполним - выводим 0, завершая ошибку
        
        return 0;
        
    }
    return (a + b) / 2; // выводим значение корня
}
int main (int argc, const char * argv[])
{
    double EPS = FEps(); // получаем значение машинного эпсилона
    double a_1 = 0; // начало отрезка для первой функции
    double b_1 = 0.85; // конец отрезка для первой функции
    double a_2 = 1; // начало отрезка для второй функции
    double b_2 = 2; // конец отрезка для второй функции
    printf("----------------------------------------------------------------------------------\n"); // выводим таблицей значения корня для первой функции
    printf("|                         Уравнение x - 1 / (3 + sin(3.6x) = 0                   |\n");
    printf("|--------------------------------------------------------------------------------|\n");
    printf("|       Метод дихотомии     |      Метод Ньютона     |      Метод Итераций       |\n");
    printf("|--------------------------------------------------------------------------------|\n");
    printf("|       %.12f      |      %.12f    |      %.12f       |\n", Dikhotomy(a_1, b_1, EPS, Func1), Newton (a_1, b_1, EPS, Func1, Func1_diff, Func1_diff2), Iterations(a_1, b_1, EPS, Root_Func1, Root_Func1_diff));
    printf("|--------------------------------------------------------------------------------|\n");
    printf("\n");
    if (Iterations(a_1, b_1, EPS, Root_Func1, Root_Func1_diff) == 0) { // если какой-то метод неприменим - выведем уведомление об этом
        printf("Метод итераций неприменим\n");
    }
    if (Dikhotomy(a_1, b_1, EPS, Func1) == 0) {
        printf("Метод дихотомии неприменим\n");
    }
    if (Newton(a_1, b_1, EPS, Func1, Func1_diff, Func1_diff2) == 0) {
        printf("Метод Ньютона неприменим\n");
    }
    printf("----------------------------------------------------------------------------------\n"); // выводим таблицей значения корня для второй функции
    printf("|                         Уравнение 0,1x^2 - xlnx = 0                            |\n");
    printf("|--------------------------------------------------------------------------------|\n");
    printf("|       Метод дихотомии     |      Метод Ньютона     |      Метод Итераций       |\n");
    printf("|--------------------------------------------------------------------------------|\n");
    printf("|       %.12f      |      %.12f    |      %.12f       |\n", Dikhotomy(a_2, b_2, EPS, Func2), Newton (a_2, b_2, EPS, Func2, Func2_diff, Func2_diff2), Iterations(a_2, b_2, EPS, Root_Func2, Root_Func2_diff));
    printf("|--------------------------------------------------------------------------------|\n");
    if (Iterations(a_2, b_2, EPS, Root_Func2, Root_Func2_diff) == 0) { // если какой-то метод неприменим - выведем уведомление об этом
        printf("Метод итераций неприменим\n");
    }
    if (Dikhotomy(a_2, b_2, EPS, Func2) == 0) {
        printf("Метод дихотомии неприменим\n");
    }
    if (Newton(a_2, b_2, EPS, Func2, Func2_diff, Func2_diff2) == 0) {
        printf("Метод Ньютона неприменим\n");
    }
    return 0;
}
        






