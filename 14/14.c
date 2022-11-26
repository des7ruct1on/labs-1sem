/*
    Ляпин Иван М8О-104Б-22
    Лабораторная работа № 14
    Вариант: 20
                
                */


#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, const char * argv[])
{
    int n; // порядок матрицы
    printf("Введите порядок матрицы\n");
    scanf("%d", &n); // считываем значение
    int a[n][n]; // двумерный массив(матрица)
    printf("Введите элементы введённой матрицы\n");
    for (int i = 0;i < n;i++) {
        // запускаем цикл по заполнению элементов в матрицу с клавиатуры
        for (int j = 0;j < n;j++) {
            
            scanf("%d", &a[i][j]);
        }
    }
    int num_elem = n * n; // кол-во элементов в матрице
    int deltaStrCol = 0; // вводим параметр, отвечающий за уменьшение строк и столбцов
    int k;
    int c = 1; // число уже выведенных(на момент в цикле) элементов на экран спиралью
    
    printf("%d", a[n-1][n-1]); // выводим элемент из правого нижнего угла
    
    while(c < num_elem) { // цикл вывода будет выполняться, пока не будут выведены все эл-ты матрицы
        // выводим угол при движении вправо
        for(k = n - 1;k >= n - 2 - deltaStrCol;k--) {
                printf("%3d", a[n - 2 - deltaStrCol][k]);
                c++;
        }
        for(k = n - 1 - deltaStrCol;k <= n - 1;k++) {
                printf("%3d", a[k][n - 2 - deltaStrCol]);
                
                c++;
        }
        deltaStrCol++; //увеличичваем параметр, так как только что закончился вывод угла справа-налево, последующий вывод будет иметь большое кол-во элементов за счет нахождения на один столбец и строку меньше
        
        //проверка, чтобы не выводить ненужный "мусор"
        if(c == num_elem) {
            break;
        }
        // выводим угол при движении влево
        for(k = n - 1;k >= n - 2 - deltaStrCol;k--) {
                printf("%3d", a[k][n - 2 - deltaStrCol]);
                c++;
        }
        for(k = n - 1 - deltaStrCol;k <= n - 1;k++) {
                printf("%3d", a[n - 2 - deltaStrCol][k]);
                c++;
        }
        
        deltaStrCol++; // увеличиваем параметр, закончили вывод угла слева-направо 
        
        
    }
    
    return 0;

}

