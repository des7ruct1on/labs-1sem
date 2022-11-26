/*
    Ляпин Иван Алексеевич
    М8О-104Б-22
    Вариант №9
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
    FILE *file; // "создаем" файл
    file = fopen("input.txt", "r"); // открываем его   c разрешением на чтение

    if (file == NULL) { // проверка на возможность открытия файла
        printf("Не удалось открыть файл!");
    }
    char c; //элемент, что считываем из файла
    int num_count = 0; //количество элементов матрицы
    bool digit_find = false; // boolean переменная, отвечающая за факт нахождения числа в файле
    while (!feof(file)) { // создаем цикл, выполняющийся пока файл не будет пустыm
        while (c = fgetc(file)) {
            if (isdigit(c) && digit_find == false) { // встретили число в файле
                digit_find = true; // нашли число, присваиваем значение true
                num_count += 1; // увеличиваем счетчик найденных слов
            }
            if (isspace(c) && digit_find == true) { // встретили пробел, при этом до этого было встречено число, следовательно число закончилось, ищем числа дальше
                digit_find = false;
            }
            if (c == EOF) { // проверка на встречу EOF в файле
                break;
            }
        }
    }
    int n = pow(num_count, 0.5); // так как матрица квадратичная, то корень из кол-ва её элементов будет являться её порядком
    int b[num_count]; // массив, в котором будем производить сдвиги
    int move; // считываемый с клавиатуры сдвиг
    int counter_str = 0; // счетчик выведенных элементов в строке
    file = fopen("/Users/ivan/Desktop/лабы/labs/input.txt", "r"); // открываем файл для сканирования элементов
    while (!feof(file)) {
        for (int i = 0;i < num_count;i++) {
            fscanf(file, "%d", &b[i]);
        }
    }
    fclose(file); // закрываем файл, в котором работали
    printf("Введите значение сдвига:\n");
    scanf("%d", &move); // считываем значение сдвига
    for (int i = 0;i < move;i++) { // цикл сдвига на единицу, повторяющийся move раз
            int last_num = b[num_count - 1]; // запоминаем последний элемент
            for (int i = num_count - 2;i >= 0;i--) { // сдвигаем все элементы, не считая того, что уже запомнили
                b[i+1] = b[i];
            }
            b[0] = last_num; // последний элемент становится первым
        }
    printf("Результат:\n");
    for (int i = 0;i < num_count; i++) {
        printf("%d\t", b[i]); // выводим элементы строки
        counter_str++;
        if (counter_str == n) { // если вывели все эл-ты строки, то выводим перенос строки
            printf("\n");
            counter_str = 0;
        }
        
    }
    
    return 0;

}
        


